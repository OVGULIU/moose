/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef THERMALCONTACTMATERIALSACTION_H
#define THERMALCONTACTMATERIALSACTION_H

#include "Action.h"

class ThermalContactMaterialsAction : public Action
{
public:
  ThermalContactMaterialsAction( const InputParameters & params);
  ThermalContactMaterialsAction(const std::string & deprecated_name, InputParameters parameters); // DEPRECATED CONSTRUCTOR
  virtual ~ThermalContactMaterialsAction(){}
  virtual void act();
};

template<>
InputParameters validParams<ThermalContactMaterialsAction>();

#endif
