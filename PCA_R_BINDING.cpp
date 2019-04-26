
// imports or headers needed 


#include <mlpack/methods/pca/pca.hpp> // particular algorithm used here.

#include <RcppArmadillo.h>
#include <Rcpp.h>
//' Run A Principal Components Analysis (with optional dimensionality reduction)
//'
//' This function performs Principal Components Analysis on a data matrix optionally with dimensionality reduction.
//' It is a standard data preprocessing procedure for producing  linearly uncorrelated predictors.
//'
//'@title run a principal components analysis with optional dimensionality reduction
//'@param decomposition method a string defaults to 'exact'
//'@param MatX a data matrix to perform PCA on
//'R format to be tranposed to mlpack format
//'@param new dimensionality an int if 0 performs no dimensionality reduction defaults to 0
//'@param scale a boolean flag if set variance of features will be scaled to 1
//'@param var to retain a double Amount of variance to retain falling between 0 and 1 defaults to 0
//'@return A matrix with PCA performed on it
// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;
using namespace mlpack;



// [[Rcpp::export]]
List PCA(List input_parameters) { 
// don't forget to declare argument types in line above
//int main
  
 static void ResetTimers()
 static void EnableTimers()
 static void DisableBacktrace()
 static void DisableVerbose()
CLI.RestoreSettings("Principal Components Analysis")
  // doesn't return template deduction error like other implementations
   LogicalVector CopyRef = input_parameters[5];
   bool copy_all_inputs = is_true( any(CopyRef) ) ;
if (copy_all_inputs == true)
{
  const std::string copyPuts = CLI::GetParam<std::string>('copy_all_inputs');  
  // CLI.SetParam[bool](<const string> 'copy_all_inputs', copy_all_inputs);

// alternatively Rccp::as < arma::mat >(Rmat); or other R object name
input_tuple = to_matrix(inputs, dtype=double, copy=CLI.HasParam('copy_all_inputs'));
input_mat = arma(input_tuple[0],input_tuple[1]);
  SetParam[arma.Mat[double]](<const string> 'input', dereference(input_mat));
  CLI.SetPassed(<const string>'input');
del input_mat;
}

// detect if the parameter was passed; set if so.
 string decomposition_method = input_parameters["DecompositionMethod"];
if (decomposition_method != "exact")
{
SetParam[string](<const string>'decomposition_method', decomposition_method.encode("UTF-8"));
CLI.SetPassed(<const string>'decomposition_method');
}

// detect if the parameter was passed; set if so.
 double new_dimensionality = input_parameters["NewDimensionality"];
if (new_dimensionality != 0)
{
SetParam[int](<const string>'new_dimensionality', new_dimensionality);
CLI.SetPassed(<const string>'new_dimensionality');
}

//detect if the parameter was passed; set if so.
 LogicalVector scaleT = input_parameters[3];
 bool scale = is_true( any(scaleT) ) ;
if (scale != false)
{
SetParam[bool](<const string>'scale', scale);
CLI.SetPassed(<const string> 'scale');
}

//detect if the parameter was passed; set if so.
 int var_to_retain = input_parameters["varToRetain"];
if (var_to_retain > 0)
{
SetParam[int](<const string>'var_to_retain', var_to_retain);
CLI.SetPassed(<const string> 'var_to_retain');
}

//detect if the parameter was passed; set if so.
 LogicalVector verbT = input_parameters[6];
 bool verbose = is_true( any(verbT) ) ;
 if (verbose != false)
{
SetParam[bool](<const string>'verbose', verbose);
CLI.SetPassed(<const string>'verbose');
EnableVerbose();
}

//Mark all out options as passed
CLI<string>.SetPassed(<const string>'verbose');

 mlpackMain();



CLI.ClearSettings()

//iniatilize results list as R idiom for python dict with name value pairs schematic
//List::create is an implicit call to Rcpp::wrap() which returns an R object or converts from C++ to R types
//extensible to third party types
//included Rccp::as() might be over kill here.
 
  return result = Rcpp::wrap(List::create(Named('output') = as<NumericMatrix>(CLI.GetParam[arma.Mat[double]], 'output')));
}
/***R
 input_paramaters <- list(data = matrix(1:16, 4, 4), decompositionMethod = "exact", newDimensionality = c(0), Scale = c(FALSE), varToRetain = c(0), copyTheInputs = c(FALSE), verboseOut = c(FALSE))
 PCA()
 ***/
