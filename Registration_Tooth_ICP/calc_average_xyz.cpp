#include "calc_average_xyz.h"

void calc_average_xyz(STLINFO &info_jaw) {

	XYZ sum(0.0);

	for (unsigned int i = 0; i < info_jaw.num_of_triangle; i++) {
		sum.x += info_jaw.triangle[i].first.x + info_jaw.triangle[i].second.x + info_jaw.triangle[i].third.x;
		sum.y += info_jaw.triangle[i].first.y + info_jaw.triangle[i].second.y + info_jaw.triangle[i].third.y;
		sum.z += info_jaw.triangle[i].first.z + info_jaw.triangle[i].second.z + info_jaw.triangle[i].third.z;
	}

	info_jaw.average_xyz.x = sum.x / ((float)info_jaw.num_of_triangle * (float)3);
	info_jaw.average_xyz.y = sum.y / ((float)info_jaw.num_of_triangle * (float)3);
	info_jaw.average_xyz.z = sum.z / ((float)info_jaw.num_of_triangle * (float)3);
}