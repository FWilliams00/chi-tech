#ifndef _chi_sweep_h
#define _chi_sweep_h

#include "../chi_mesh.h"
#include <set>


//###################################################################
namespace chi_mesh
{
namespace sweep_management
{
  struct STDG;           ///< Global Sweep Plane Ordering
  struct SPLS;           ///< Sweep Plane Local Subgrid
  class  PRIMARY_FLUDS;  ///< Primary Flux Data Structure
  class  AUX_FLUDS;      ///< Auxiliary Flux Data Structure
  struct SPDS;           ///< Sweep Plane Data Structure

  class  SweepBuffer;
  class AngleSet;
  class AngleSetGroup;
  class  AngleAggregation;

  class SweepChunk;

  class SweepScheduler;

  SPDS* CreateSweepOrder(double polar, double azimuthal,
                         chi_mesh::MeshContinuum *vol_continuum,
                         int number_of_groups,
                         bool allow_cycles=false);

  void PopulateCellRelationships(
            chi_mesh::MeshContinuum *grid,
            chi_mesh::sweep_management::SPDS* sweep_order,
            std::vector<std::set<int>>& cell_dependencies,
            std::vector<std::set<int>>& cell_successors);

  void PrintSweepOrdering(SPDS* sweep_order,
                          MeshContinuum* vol_continuum);

  enum class AngleSetStatus{
    NOT_FINISHED = 0,
    FINISHED = 1,
    RECEIVING = 2,
    READY_TO_EXECUTE = 3,
    EXECUTE = 4,
    NO_EXEC_IF_READY = 5
  };
  typedef AngleSetStatus ExecutionPermission;
}
}

#include "sweepchunk_base.h"

#endif