#include "translation_to_origin.h"

void translation_to_origin(STLINFO & jaw1, STLINFO & jaw2){

	for (unsigned int i = 0; i < jaw1.num_of_triangle; i++) {
		jaw1.triangle[i].first.x  -= jaw1.average_xyz.x; jaw1.triangle[i].first.y  -= jaw1.average_xyz.y; jaw1.triangle[i].first.z  -= jaw1.average_xyz.z;
		jaw1.triangle[i].second.x -= jaw1.average_xyz.x; jaw1.triangle[i].second.y -= jaw1.average_xyz.y; jaw1.triangle[i].second.z -= jaw1.average_xyz.z;
		jaw1.triangle[i].third.x  -= jaw1.average_xyz.x; jaw1.triangle[i].third.y  -= jaw1.average_xyz.y; jaw1.triangle[i].third.z  -= jaw1.average_xyz.z;
	}

	for (unsigned int i = 0; i < jaw2.num_of_triangle; i++) {
		jaw2.triangle[i].first.x  -= jaw2.average_xyz.x; jaw2.triangle[i].first.y  -= jaw2.average_xyz.y; jaw2.triangle[i].first.z  -= jaw2.average_xyz.z;
		jaw2.triangle[i].second.x -= jaw2.average_xyz.x; jaw2.triangle[i].second.y -= jaw2.average_xyz.y; jaw2.triangle[i].second.z -= jaw2.average_xyz.z;
		jaw2.triangle[i].third.x  -= jaw2.average_xyz.x; jaw2.triangle[i].third.y  -= jaw2.average_xyz.y; jaw2.triangle[i].third.z  -= jaw2.average_xyz.z;
	}

}
