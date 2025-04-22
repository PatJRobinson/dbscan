#pragma once


#include <cassert>
#include <cstddef>
#include <vector>
#include <cstdlib>

#ifdef _WIN32
  #ifdef SENSUS_SHARED
    #ifdef BUILDING_DBSCAN_DLL
      // When building the DLL, export the symbols.
      #define DBSCAN_API __declspec(dllexport)
    #else
      // When using the DLL, import the symbols.
      #define DBSCAN_API __declspec(dllimport)
    #endif
  #else
    #define DBSCAN_API
  #endif
#else
  #define DBSCAN_API
#endif

struct point2
{
    float x, y;
};

struct point3
{
    float x, y, z;
};

[[nodiscard]] DBSCAN_API auto dbscan(const std::vector<point2>& data, float eps, int min_pts) -> std::vector<std::vector<size_t>>;
[[nodiscard]] DBSCAN_API auto dbscan(const std::vector<point3>& data, float eps, int min_pts) -> std::vector<std::vector<size_t>>;

// template<size_t dim>
// auto dbscan(const std::vector<float>& data, float eps, int min_pts)
// {
//     static_assert(dim == 2 or dim == 3, "This only supports either 2D or 3D points");
//     assert(data.size() % dim == 0);
    
//     if(dim == 2)
//     {
//         auto * const ptr = reinterpret_cast<float const*> (data.data());
//         auto points = std::vector<point2> 
//     }
// }