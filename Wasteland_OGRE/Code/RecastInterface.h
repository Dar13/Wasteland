#include "StdAfx.h"

#include <Recast.h>

#ifndef _RECAST_INTERFACE_H_
#define _RECAST_INTERFACE_H_

class RecastConfiguration
{
public:
	RecastConfiguration()
		: _cellSize(0.3f),
		  _cellHeight(0.2f),
		  _agentMaxSlope(20.0f),
		  _agentHeight(2.5f),
		  _agentRadius(.2f),
		  _edgeMaxLength(12.0f),
		  _edgeMaxError(1.3f),
		  _regionMinSize(50),
		  _regionMergeSize(20),
		  _verticesPerPolygon(6),
		  _detailSampleDistance(6),
		  _detailSampleMaxError(1)
	{
		eval();
	}
private:
	inline void eval()
	{
		_walkableHeight = static_cast<int>(ceilf(_agentHeight / _cellHeight));
		_walkableClimb = static_cast<int>(floorf(_agentMaxClimb / _cellHeight));
		_walkableRadius = static_cast<int>(ceilf(_agentRadius / _cellSize));
		_maxEdgeLength = static_cast<int>(_edgeMaxLength / _cellSize);
		_minRegionArea = static_cast<int>(_regionMinSize * _regionMinSize);
		_mergeRegionArea = static_cast<int>(_regionMergeSize * _regionMergeSize);
		__detailSampleDist = _detailSampleDistance < 0.9f ? 0.0f : _cellSize * _detailSampleDistance;
		__detailSampleMaxError = _cellHeight * _detailSampleMaxError;
	}

	//For full explanation of some of the member variables go here:
	//https://github.com/duststorm/OgreRecastDemo/blob/master/include/OgreRecast.h
	/*
	Cellsize (cs) is the width and depth resolution used when sampling the source geometry.
	The width and depth of the cell columns that make up voxel fields.
	Cells are laid out on the width/depth plane of voxel fields. Width is associated with
	the x-axis of the source geometry. Depth is associated with the z-axis. A lower value 
	allows for the generated meshes to more closely match the source geometry, but at a 
	higher processing and memory cost.
	
	The xz-plane cell size to use for fields. [Limit: > 0] [Units: wu].
	cs and ch define voxel/grid/cell size. So their values have significant side effects on 
	all parameters defined in voxel units. The minimum value for this parameter depends on 
	the platform's floating point accuracy, with the practical minimum usually around 0.05.
	*/
	float _cellSize;

	/*
	Cellheight (ch) is the height resolution used when sampling the source geometry. The 
	height of the voxels in voxel fields. Height is associated with the y-axis of the 
	source geometry. A smaller value allows for the final meshes to more closely match the 
	source geometry at a potentially higher processing cost.
	(Unlike cellSize, using a lower value for cellHeight does not significantly increase memory use.)
    
	The y-axis cell size to use for fields. [Limit: > 0] [Units: wu].
	cs and ch define voxel/grid/cell size. So their values have significant side effects 
	on all parameters defined in voxel units. The minimum value for this parameter depends on 
	the platform's floating point accuracy, with the practical minimum usually around 0.05.
    
	Setting ch lower will result in more accurate detection of areas the agent can still pass 
	under, as min walkable height is discretisized in number of cells. Also walkableClimb's 
	precision is affected by ch in the same way, along with some other parameters.
	*/
	float _cellHeight;

	/*
	Maximum slope that is considered traversable(in degrees(!!)).
	0 <= value < 90
	Practical upper limit is ~85 degrees
	Alias: maxTraversableSlope
	*/
	float _agentMaxSlope;

	/*
	Height of an agent. Defines minimum height that agents can walk under.

	Alias: minTraversableHeight
	*/
	float _agentHeight;

	/*
	The Maximum ledge height that is considered to still be traversable.
	This parameter serves at setting walkableClimb (maxTraversableStep) 
	parameter, precision of this parameter is determined by cellHeight (ch).
	[Limit: >=0]
	Allows the mesh to flow over low lying obstructions such as curbs and up/down stairways. 
	The value is usually set to how far up/down an agent can step.
	*/
	float _agentMaxClimb;

	//Radius of agent. Used in Detour too.
	float _agentRadius;

	//Maximum length of contour edges. Vertices will be added as needed to keep this value true.
	float _edgeMaxLength;

	//Maximum allowed error for contour border edges.
	//Aliases: maxSimplificationError,edgeMaxDeviation
	float _edgeMaxError;

	//Minimum number of cells allowed to form isolated island areas(size).
	//Limit: >= 0
	float _regionMinSize;

	//If a region is smaller than this value will,if possible, be merged with a larger region
	//Limit: >= 0 [ unit: voxel ]
	float _regionMergeSize;

	//Maximum amount of vertices allowed for polygons in the nav mesh
	//Limit: >= 3
	//Higher values = higher processing cost, better formed meshes
	int _verticesPerPolygon;

	//Sets sampling distance to use when generating the detail mesh(height detail only).
	//Limits: 0 or >= .9 [ unit: wu(??) ]
	float _detailSampleDistance;

	//Maximum distance the detail mesh surface should deviate from the heightfield data(height detail only).
	//Limit: >= 0 [ unit: wu(??) ]
	//Alias: contourMaxDeviation
	float _detailSampleMaxError;

	bool _keepIntermediateResults;

	//Minimum height in # of cells that the ceiling needs to be. Related to _agentHeight & _cellHeight
	//Limit: >= 3 [ unit: vx]
	//Aliases: minTraversableHeight
	//Note: This should be at least (2*_cellHeight).
	int _walkableHeight;

	//Maximum ledge height that is walkable in # of cells
	//Limit: >= 0 [ unit: vx ]
	//Mesh flows over small lowlying obstructions
	int _walkableClimb;

	//Distance to erode/shrink walkable area in cell size units
	//Limit: >= 0 [ unit: vx ]
	//Alias: traversableAreaBorderSize
	//Note: should be > _cellSize to have any effect.
	int _walkableRadius;

	//Limit: >= 0 [ unit: vx ]
	//Alias: maxEdgeLength
	int _maxEdgeLength;

	//Minimum # of cells allowed to form isolated island areas
	//Limit: >= 0 [ unit: vx ]
	//Alias: minUnconnectedRegionSize
	int _minRegionArea;

	//Any regions with a span count < this # will be merged into larger region(if possible)
	//Limit: >= 0 [ unit: vx ]
	//Aliases: mergeRegionSize or mergeRegionArea
	int _mergeRegionArea;

	//The following two variables have an extra underscore to avoid a variable name conflict.

	//Sampling distance used when generating detail mesh
	//Limits: 0 or >= .9 [ unit: wu ]
	float __detailSampleDist;

	//Maximum distance the detail mesh surface should deviate from the heightfield data
	//Limit: >= 0 [ unit: wu ]
	float __detailSampleMaxError;
};

class RecastInterface
{
public:

private:

};

#endif