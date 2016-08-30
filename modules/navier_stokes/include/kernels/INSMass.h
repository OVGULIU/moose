/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef INSMASS_H
#define INSMASS_H

#include "Kernel.h"

// Forward Declarations
class INSMass;

template<>
InputParameters validParams<INSMass>();

/**
 * This class computes the mass equation residual and Jacobian
 * contributions for the incompressible Navier-Stokes momentum
 * equation.
 */
class INSMass : public Kernel
{
public:
  INSMass(const InputParameters & parameters);

  virtual ~INSMass(){}

  enum COORD_TYPE
  {
    XYZ,
    RZ,
    RSPHERICAL
  };

  static void setGeometryParameter(const InputParameters & params, COORD_TYPE & coord_type);

protected:
  virtual void computeResidual();
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned jvar);

  bool _coord_type_set;
  COORD_TYPE _coord_type;

  // Coupled values
  const VariableValue & _u_vel;


  // Coupled Gradients
  const VariableGradient & _grad_u_vel;
  const VariableGradient & _grad_v_vel;
  const VariableGradient & _grad_w_vel;

  // Variable numberings
  unsigned _u_vel_var_number;
  unsigned _v_vel_var_number;
  unsigned _w_vel_var_number;
  unsigned _p_var_number;
};


#endif // INSMASS_H
