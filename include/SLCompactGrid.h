//#############################################################################
//  File:      SLCompactGrid.h
//  Author:    Manuel Frischknecht, Marcus Hudritsch
//  Date:      July 2015
//  Copyright: Manuel Frischknecht, Marcus Hudritsch
//             This software is provide under the GNU General Public License
//             Please visit: http://opensource.org/licenses/GPL-3.0
//#############################################################################

#ifndef SL_COMPACTGRID
#define SL_COMPACTGRID

#include <stdafx.h>

#include <array>
#include <vector>
#include <numeric>
#include <atomic>

#include <SLVec3.h>
#include <SLAccelStruct.h>

//-----------------------------------------------------------------------------
//! Class for compact uniform grid acceleration structure
/*! This class implements the data structure proposed by Lagae & Dutre in their
paper "Compact, Fast and Robust Grids for Ray Tracing". It reduces the memory
footprint to a quarter of a regular uniform grid implemented in SLUniformGrid.
*/
class SLCompactGrid : public SLAccelStruct
{
    public:
    using Triangle = std::array<SLVec3f,3>;

                            SLCompactGrid   (SLMesh* m);
                           ~SLCompactGrid   (){;}

                void        build           (SLVec3f minV, SLVec3f maxV);
                void        updateStats     (SLNodeStats &stats);
                void        draw            (SLSceneView* sv);
                SLbool      intersect       (SLRay* ray, SLNode* node);

				void        deleteAll       (){}
                void        disposeBuffers  (){}

                SLuint      indexAtPos      (const SLVec3i &p) const 
                                            {return p.x + p.y*_size.x + p.z*_size.x * _size.y;}
                SLVec3f     voxelCenter     (const SLVec3i &pos) const;
                SLVec3i     containingVoxel (const SLVec3f &p) const;
                void        setMinMaxVoxel  (const Triangle &triangle, 
                                             SLVec3i &minCell, 
                                             SLVec3i &maxCell);
    private:
                SLVec3i     _size;              //!< num. of voxel in grid dir.
                SLfloat     _voxelWidth;        //!< voxel width
                SLVuint     _voxelOffsets;      //!< Offset array (C in the paper)
                SLVuint     _triangleIndexes;   //!< Triangle index array (L in the paper)
                SLGLBuffer  _bufP;              //!< Buffer object for vertex positions
};
//-----------------------------------------------------------------------------
#endif //SL_COMPACTGRID
