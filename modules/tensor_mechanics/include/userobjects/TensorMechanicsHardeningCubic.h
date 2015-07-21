/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef TENSORMECHANICSHARDENINGCUBIC_H
#define TENSORMECHANICSHARDENINGCUBIC_H

#include "TensorMechanicsHardeningModel.h"

class TensorMechanicsHardeningCubic;


template<>
InputParameters validParams<TensorMechanicsHardeningCubic>();

/**
 * Cubic hardening
 * value = _val_0 for p <= _intnl_0
 * value = _val_res for p >= _intnl_limit
 * value = cubic betwen _val_0 at p = _intnl_0, and _val_res at p = _intnl_limit
 * The cubic is smooth, which means nice numerical properties
 */
class TensorMechanicsHardeningCubic : public TensorMechanicsHardeningModel
{
 public:
  TensorMechanicsHardeningCubic(const InputParameters & parameters);
  TensorMechanicsHardeningCubic(const std::string & deprecated_name, InputParameters parameters); // DEPRECATED CONSTRUCTOR

  virtual Real value(const Real & intnl) const;

  virtual Real derivative(const Real & intnl) const;

 private:

  /// value is cubic between _val_0 at internal_parameter=_intnl_0, at _val_res at internal_parameter=_intnl_limit
  Real _val_0;

  /// value is cubic between _val_0 at internal_parameter=_intnl_0, at _val_res at internal_parameter=_intnl_limit
  Real _val_res;

  /// value is cubic between _val_0 at internal_parameter=_intnl_0, at _val_res at internal_parameter=_intnl_limit
  Real _intnl_0;

  /// value is cubic between _val_0 at internal_parameter=_intnl_0, at _val_res at internal_parameter=_intnl_limit
  Real _intnl_limit;

  /// convenience parameter for cubic
  Real _half_intnl_limit;

  /// convenience parameter for cubic
  Real _alpha;

  /// convenience parameter for cubic
  Real _beta;

};

#endif // TENSORMECHANICSHARDENINGCUBIC_H
