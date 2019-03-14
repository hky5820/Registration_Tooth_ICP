#pragma once
#include <Eigen/Dense>
#include "STLINFO.h"

using namespace Eigen;
using namespace std;

void calc_alignment(vector<pair<XYZ, XYZ>> &pair_closest_point, Matrix4f &mat_result_of_alignment);