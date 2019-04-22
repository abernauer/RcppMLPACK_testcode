
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
Rcpp::List PCA(const string decomposition_method = "exact",
	       arma::matrix& MatX,
	       arma::matrix& MatY,
	       const int new_dimensionality = 0,
	       const bool scale = false,
	       const double var_to_retain = 0){
  MatX = MatX.t();

  
  mlpack::pca::PCA<>.Apply(const arma::mat & MatX,
			   arma::mat & MatY.t(),
			   arma::vec & eigVal,
			   arma::mat & eigVec
			   );
  return List::Create output(Named("decomposition_method") = decomposition_method,
			     Named("transformed_matrix") = MatY.t());
}
