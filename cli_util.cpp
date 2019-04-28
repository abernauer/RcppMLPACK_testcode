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

 

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

  extern void mlpackSetParamDoubl(const char *identifier, double value);

  extern void mlpackSetParamInt(const char *identifier, int value);

  extern void mlpackSetParamFloat(const char *identifier, float value);

  extern void mlpackSetParamBool(const char *identifier, bool value);

  extern bool mlpackHasParam(const char *identifier);

  extern char *mlpackGetParamString(const char *identifier);

  extern double mlpackGetParamDouble(const char *identifier);

  extern int mlpackGetParamInt(const char *identifier);

  extern void *mlpackGetVecIntPtr(const char *identifier);

  extern int mlpackVecStringSize(const char *identifier);

  extern void mlpackSetPassed(const char *name);

  extern void mlpackResetTimers();

  extern void mlpackDisableBacktrace();

  extern void mlpackClearSettings();

  extern void mlpackRestoreSettings(const char *name);
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif



namespace mlpack {

  extern "C" {
  
    /**
     * Set the double parameter to the given value.
     */
   

void mlpackSetParamDouble(const char *identifier, double value)
{
      mlpack::bindings::cli::SetParam(identifier, value);
}

 /**
  * Set the int parameter to the given value.
  */
void mlpackSetParamInt(const char *identifier, int value)
{
   mlpack::bindings::cli::SetParam(identifier, value);
}

 /**
  * Set the float parameter to the given value.
  */
void mlpackSetParamFloat(const char *identifier, float value)
{
       mlpack::bindings::cli::SetParam(identifier, value);
}

 /**
  * Set the bool parameter to the given value.
  */
void mlpackSetParamBool(const char *identifier, bool value)
{
       mlpack::bindings::cli::SetParam(identifier, value);
}

 /**
  * Set the string parameter to the given value.
  */
void mlpackSetParamString(const char *identifier, const char *value)
 {
      std::string val;
      val.assign(value);
      mlpack::bindings::cli::SetParam(identifier, value);
 }

    /**
  * Set the parameter to the given value, given that the type is pointer.
  */
void mlpackSetParamPtr(const char *identifier, const double *ptr, const bool copy)
{
      mlpack::bindings::cli::SetParamPtr(identifier, ptr, value);
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
      double val = CLI::GetParam<double>(identifier);
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
      std::vector<std::string> output = static T& mlpack::CLI::GetParam(const string&);
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

void mlpackMain(){
}
  
