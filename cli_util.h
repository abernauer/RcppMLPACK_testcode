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
extern "C"{
#endif

  /**
   * Set the double parameter to the given value
   */
  extern void mlpackSetParamDouble(const char *identifier, double value);

  extern void mlpackSetParamInt(const char *identifier, int value);

  extern void mlpackSetParamFloat(const char *identifier, float value);

  extern void mlpackSetParamBool(const char *identifier, bool value);

  extern void mlpackSetParamString(const char *identifier, const char *value);

  extern void mlpackSetParamPtr(const char *identifier, const double *ptr, const bool copy);

  extern bool mlpackHasParam(const char *identifier);

  extern char *mlpackGetParamString(const char *identifier);

  extern double mlpackGetParamDouble(const char *identifier);

  extern int mlpackGetParamInt(const char *identifier);

  extern void *mlpackGetVecIntPtr(const char *identifier);

  extern void *mlpackGetVecStringPtr(const char *identifier);

  extern int mlpackVecIntSize(const char *identifier);

  extern int mlpackVecStringSize(const char *identifier);

  extern void mlpackSetPassed(const char *name);

  extern void mlpackResetTimers();

  extern void mlpackEnableTimers();

  extern void mlpackDisableBacktrace();

  extern void mlpackClearSettings();

  extern void mlpackRestoreSettings(const char *name);
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
