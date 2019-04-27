/**
 * @file cli_util.cpp
 *
 *Utility functions for R to set and get parameters to and from the CLI.
 *
 */
#include "cli_util.h"
#include "cli_util.hpp"
#include <mlpack/core/util/cli.hpp>

namespace mlpack {

  extern "C" {

    /**
     * Set the double parameter to the given value.
     */
    void mlpackSetParamDouble(const char *identifier, double value)
    {
      util::SetParam(identifier, value);
    }

 /**
  * Set the int parameter to the given value.
  */
void mlpackSetParamInt(const char *identifier, int value)
{
  util::SetParam(identifier, value);
}

 /**
  * Set the float parameter to the given value.
  */
    void mlpackSetParamFloat(const char *identifier, float value)
    {
      util::SetParam(identifier, value);
    }

 /**
  * Set the bool parameter to the given value.
  */
    void mlpackSetParamBool(const char *identifier, bool value)
    {
      util::SetParam(identifier, value);
    }

 /**
  * Set the string parameter to the given value.
  */
    void mlpackSetParamString(const char *identifier, const char *value)
    {
      std::string val;
      val.assign(value);
      util::SetParam(identifier, val);
    }

    /**
  * Set the parameter to the given value, given that the type is pointer.
  */
    void mlpackSetParamPtr(const char *identifier, const double *ptr, const bool copy)
    {
      util::SetParamPtr(identifier, ptr, copy);
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
    bool mlpackGetParamBool(const char *identifieer)
    {



