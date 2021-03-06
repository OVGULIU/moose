//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "CommonTensorMechanicsAction.h"
#include "TensorMechanicsAction.h"

registerMooseAction("TensorMechanicsApp", CommonTensorMechanicsAction, "meta_action");

template <>
InputParameters
validParams<CommonTensorMechanicsAction>()
{
  InputParameters params = validParams<TensorMechanicsActionBase>();
  return params;
}

CommonTensorMechanicsAction::CommonTensorMechanicsAction(const InputParameters & parameters)
  : Action(parameters)
{
}
