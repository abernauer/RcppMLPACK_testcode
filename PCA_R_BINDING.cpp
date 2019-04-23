
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
Rcpp::List PCA(input, copy_all_input=false, scale=false, var_to_retain=none, verbose=false){
ResetTimers();
EnableTimers();
DisableBacktrace();
DisableVerbose();
CLI.RestoreSettings("Principal Components Analysis");
if (copy_all_inputs == true){
CLI.SetParam[bool](<const string> 'copy_all_inputs', copy_all_inputs)

  input_tuple=to_matrix(inputs, dtype=double, copy=CLI<>.HasParam('copy_all_inputs'))
input_mat=//arma(input_tuple[0],input_tuple[1]
  SetParam[arma.Mat[double]](<const string> 'input', dereference(input_mat))
  CLI.SetPassed(<const string>'input')
  del input_mat
}

// detect if the parameter was passed; set if so.
if (decomposition_method != false) {
SetParam[int](<const string>'new_dimensionality', new_dimensionality)
CLI.SetPassed(<const string>'new_dimensionality')
}

if (scale != false){
SetParam[bool](<const string>'scale', scale)
CLI.SetPassed(<const string> 'scale')
}

if (var_to_retain != none) {
SetParam[int](<const string>'var_to_retaint', var_to_retain)
CLI.SetPassed(<const string> 'var_to_retain')
}

if (verbose != false){
SetParam[bool](<const string>'verbose', verbose)
CLI.SetParam(<const string>'verbose')
EnableVerbose()
}

//Mark all out options as passed
CLI.SetPassed(<const string>'verbose')

mlpack Main()
//result =

  CLI.ClearSettings()
  return result;
}
