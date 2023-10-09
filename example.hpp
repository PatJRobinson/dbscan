#include "dbscan.hpp"
#include <iostream>
#include <string>
#include <system_error>
#include <vector>
#include <utility>
#include <fstream>
#include <charconv>
#include <cassert>
#include <tuple>
#include <cstring>


std::vector<size_t> dbscan3d(const std::vector<float>& data, float eps, int min_pts);