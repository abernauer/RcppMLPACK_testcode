
// imports or headers needed 
#include <Rcpp.h>//  Rcpp
using namespace Rcpp;

#include <mlpack/methods/pca/pca.hpp> // particular algorithm used here.

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
// [[Rcpp::exports]]
Rcpp::List PCA(input, string decomposition_method = 'exact', const int new_dimensionality = 0, bool copy_all_input = false, bool scale = false, var_to_retain = none, verbose = false){
// don't forget to declare argument types in line above
ResetTimers();
EnableTimers();
DisableBacktrace();
DisableVerbose();
CLI.RestoreSettings("Principal Components Analysis");
if (copy_all_inputs == true){
CLI.SetParam[bool](<const string> 'copy_all_inputs', copy_all_inputs);

// alternatively Rccp::as < arma::mat >(Rmat); or other R object name
input_tuple = to_matrix(inputs, dtype=double, copy=CLI.HasParam('copy_all_inputs'));
input_mat = //arma(input_tuple[0],input_tuple[1]);
  SetParam[arma.Mat[double]](<const string> 'input', dereference(input_mat));
  CLI.SetPassed(<const string>'input');
del input_mat;
}

// detect if the parameter was passed; set if so.
if (decomposition_method != none) {
SetParam[string](<const string>'decomposition_method', decomposition_method.encode("UTF-8"));
CLI.SetPassed(<const string>'decomposition_method');
}

// detect if the parameter was passed; set if so.
if (new_dimensionality != 0) {
SetParam[int](<const string>'new_dimensionality', new_dimensionality);
CLI.SetPassed(<const string>'new_dimensionality');
}

//detect if the parameter was passed; set if so.
if (scale != false){
SetParam[bool](<const string>'scale', scale);
CLI.SetPassed(<const string> 'scale');
}

//detect if the parameter was passed; set if so.
if (var_to_retain != none) {
SetParam[int](<const string>'var_to_retaint', var_to_retain);
CLI.SetPassed(<const string> 'var_to_retain');
}

//detect if the parameter was passed; set if so.
if (verbose != false){
SetParam[bool](<const string>'verbose', verbose);
CLI.SetPassed(<const string>'verbose');
EnableVerbose();
}

//Mark all out options as passed
CLI.SetPassed(<const string>'verbose');

mlpack Main();



CLI.ClearSettings();

//iniatilize results list as R idiom for python dict with name value pairs schematic
//List::create is an implicit call to Rcpp::wrap() which returns an R object or coverts from C++ to R types
// extensable to third party types
  return result = List::create(Named('output') = Rcpp::as < arma mat >(CLI.GetParam[arma.Mat[double]], 'output'));
}
// ***R
//
//
//
// ***
