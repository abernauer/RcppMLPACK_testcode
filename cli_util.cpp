/**
 * @file cli_util.cpp
 *
 *Utility functions for R to set and get parameters to and from the CLI.
 *
 */
#include <mlpack/prereqs.hpp>
#include <mlpack/core/util/cli.hpp>
#define BINDING_TYPE BINDING_TYPE_R
#include <mlpack/core/util/mlpack_main.hpp>
#include <R.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
// [[Rcpp::plugins(openmp)]]
 




namespace mlpack{


  extern "C" {
  
    /**
     * Set the double parameter to the given value.
     */
   

void mlpackSetParamDouble(const char *identifier, double value)
{
  mlpack::bindings::cli::SetParam(identifier, value)  
}

 /**
  * Set the int parameter to the given value.
  */
void mlpackSetParamInt(const char *identifier, int value)
{
    mlpack::bindings::cli::SetParam(identifier ,  value);
}

 /**
  * Set the float parameter to the given value.
  */
void mlpackSetParamFloat(const char *identifier, float value)
{
  mlpack::bindings::cli::SetParam(identifier, value, void* / input / );
}

 /**
  * Set the bool parameter to the given value.
  */
void mlpackSetParamBool(const char *identifier, bool value)
{
 
  
        mlpack::bindings::cli::SetParam(identifier , value);
}

 /**
  * Set the string parameter to the given value.
  */
void mlpackSetParamString(const char *identifier, const char *value)
 {
      std::string val;
      val.assign(value);
    void  mlpack::bindings::cli::SetParam(identifier, value);
 }

    /**
  * Set the parameter to the given value, given that the type is pointer.
  */
void mlpackSetParamPtr(const char *identifier, const double *ptr, const bool copy)
{
      mlpack::bindings::cli::SetParam(identifier , ptr , copy);
}

    /**
  * Check if CLI has a specified parameter.
  */
bool mlpackHasParam(const char *identifier)
{
      return CLI::HasParam(identifier);
}

    /**
  *  Get the string parameter associated with specified identifier.
  */
char *mlpackGetParamString(const char *identifier)
{
      std::string val = CLI::GetParam<std::string>(identifier);
      char *cstr = const_cast<char*>(val.c_str());
      return cstr;
}
    /**
  * Get the double parameter associated with specified identifier.
  */
double mlpackGetParamDouble(const char *identifier)
{
      double val =  CLI::GetParam<double>(identifier);
      return val;
}

   /**
  * Get the int parameter associated with specified identifier.
  */
int mlpackGetParamInt(const char *identifier)
{
      int val = CLI::GetParam<int>(identifier);
      return val;
}

    /**
  * Get the bool parameter associated with specified identifier.
  */
bool mlpackGetParamBool(const char *identifier)
{
      bool val = CLI::GetParam<bool>(identifier);
      return val;
}

    /**
  * Get the vector<int> parameter associated with specified identifier.
  */
void *mlpackGetVecIntPtr(const char *identifier)
{
      // std::vector<int>  vec = CLI::GetParam<std::vector<int>>(identifier);
       // return vec.get_allocator();
}

    /**
  * Get the vector<string> parameter associated with specified identifier.
  */
 void *mlpackGetVecStringPtr(const char *identifier)
{
      // std::vector<std::string> vec = CLI::GetParam<std::vector<std::string>>(identifier);
      // return vec.get_allocator();
 }

    /**
  * Get the vector<int> parameter's size.
  */
 int mlpackVecIntSize(const char *identifier)
 {
      std::vector<int> output = CLI::GetParam<std::vector<int>>(identifier);
      return output.size();
 }

    /**
  * Get the vector<string> parameter's size.
  */
int mlpackVecStringSize(const char *identifier)
 {
   std::vector<std::string> output =  CLI::GetParam<std::vector<std::string>>(identifier);
      return output.size();
 }

    /**
    * Set paramater as passed. 
    */
void mlpackSetPassed(const char *name)
{
      CLI::SetPassed(name);
}

    /**
    * Reset the status of all timers.  
    */
void mlpackResetTimers()
{
      CLI::GetSingleton().timer.Reset();
}

    /**
    * Enable timing.
    */
void mlpackEnableTimers()
{
      Timer::EnableTiming();
}

    /**
    * Disable backtraces.
    */
 void mlpackDisableBacktrace()
{
 Log::Fatal.backtrace = false;
}

    /**
    * Turn verbose output on.
    */
void mlpackEnableVerbose()
{
      Log::Info.ignoreInput = false;
}

    /**
    * Turn verbose output off.
    */
void mlpackDisableVerbose()
{
 Log::Info.ignoreInput = true;
}

    /**
    * Clear settings. 
    */
void mlpackClearSettings()
{
 CLI::ClearSettings();
}

    /**
    * Restore Settings.
    */
void mlpackRestoreSettings(const char *name)
{
  CLI::RestoreSettings(name);
}

  } // extern C

} // namespace mlpack
using namespace mlpack;
using namespace mlpack::pca;
using namespace mlpack::util;
using namespace std;

// Document program.
PROGRAM_INFO("Principal Components Analysis",
	     // Short description.
	     "An implementation of several strategies for principal components analysis "
	     "(PCA), a commmon prepcocessing step. Given a dataset and a desired new"
	     "dimensionality, this can reduce the dimensionality of the data using the "
	     "linear transformation determined by PCA.",
	     // long description
             "This program performs principal components analysis on the given data set storing, "
	     "storing the transformed matrix with it's principal components"
	     "\n\n"
	     "The input dataset should be specificied with " +
             PRINT_PARAM_STRING("input") + ", paramater and the desired dimensionality used, for"
	     "dimensionality reduction can be specified with " + PRINT_PARAM_STRING("new_dimensionality") + " "
	     "paramater."
	     "\n\n"
	     "The output of the transformed matrix may be saved with the " +
	     PRINT_PARAM_STRING("output") + "ouput paramater."
	     "\n\n"


	     PRINT_CALL("pca", "input_file", "data",
                        "new_dimensionality", 5,
			"output", "data_mod"),
  SEE_ALSO("Principal component analysis on Wikipedia",
	   "https://en.wikipedia.org/wiki/Principal_component_analysis"),
  SEE_ALSO("mlpack::pca::PCA C++ class documentation",
	   "@doxygen/classmlpack_1_1pca_1_1PCA.html"));

// Parameters for the program.
PARAM_MATRIX_IN_REQ("input", "Input dataset to perform PCA on.", "i");
PARAM_MATRIX_OUT("output", "Matrix to save modified dataset to", "o");
PARAM_INT_IN("new_dimensionality","Desired dimensionality of output dataset.", "d", 0);

using namespace mlpack;

static void mlpackMain()
{
  //load input data set
  arma::mat& dataset = CLI::GetParam<arma::mat>("input");

  size_t newDimension = CLI::GetParam<int>("new_dimensionality");

  // Now save the results
  if (CLI::HasParam("output"))
    CLI::GetParam<arma::mat>("output") = std::move(dataset);
}
  
