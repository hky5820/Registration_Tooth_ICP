#pragma once
#include <Eigen/Dense>
#include "STLINFO.h"
#include "kdtree.h"

void calc_closest_point(STLINFO & info_jaw1, STLINFO & info_jaw2, vector<pair<XYZ, XYZ>> &pair_closest_point);