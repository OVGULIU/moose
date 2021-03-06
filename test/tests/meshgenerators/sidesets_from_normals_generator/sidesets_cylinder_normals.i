[MeshGenerators]
  [./fmg]
    type = FileMeshGenerator
    file = cylinder.e
    #parallel_type = replicated
  []

  [./sidesets]
    type = SideSetsFromNormalsGenerator
    input = fmg
    normals = '0  0  1
               0  1  0
               0  0 -1'
    fixed_normal = false
    new_boundary = 'top side bottom'
  []
[]

[Mesh]
  type = MeshGeneratorMesh
[]

[Variables]
  [./u]
  [../]
[]

[Kernels]
  [./diff]
    type = Diffusion
    variable = u
  [../]
[]

[BCs]
  [./bottom]
    type = DirichletBC
    variable = u
    boundary = bottom
    value = 0
  [../]
  [./top]
    type = DirichletBC
    variable = u
    boundary = top
    value = 1
  [../]
[]

[Executioner]
  type = Steady

  solve_type = 'PJFNK'

  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
