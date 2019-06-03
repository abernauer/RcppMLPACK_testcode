/**
 * @file cli_util.h
 *
 *Header file for Rcpp to call C functions from R.
 *
 *
 */
#ifndef MLPACK_BINDINGS_R_MLPACK_CLI_UTIL_H
#define MLPACK_BINDINGS_R_MLPACK_CLI_UTIL_H

#include <stdint.h>
#include <stdef.h>
#include <stdbool.h>

#if defined(__cplusplus) || defined(c_plusplus)
extern "C"{            //disables name mangling by the compiler
                       //for the following functions
#endif

  /**
   * Set the double parameter to the given value
   */

  void mlpackSetParamDouble(const char *identifier, double value);

  void mlpackSetParamInt(const char *identifier, int value);

  void mlpackSetParamFloat(const char *identifier, float value);

  void mlpackSetParamBool(const char *identifier, bool value);

  void mlpackSetParamString(const char *identifier, const char *value);

  void mlpackSetParamPtr(const char *identifier, const double *ptr, const bool copy);

  bool mlpackHasParam(const char *identifier);

  char *mlpackGetParamString(const char *identifier);

  double mlpackGetParamDouble(const char *identifier);

  int mlpackGetParamInt(const char *identifier);

  void *mlpackGetVecIntPtr(const char *identifier);

  void *mlpackGetVecStringPtr(const char *identifier);

  int mlpackVecIntSize(const char *identifier);

  int mlpackVecStringSize(const char *identifier);

  void mlpackSetPassed(const char *name);

  void mlpackResetTimers();

  void mlpackEnableTimers();

  void mlpackDisableBacktrace();

  void mlpackClearSettings();

  void mlpackRestoreSettings(const char *name);

  
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
