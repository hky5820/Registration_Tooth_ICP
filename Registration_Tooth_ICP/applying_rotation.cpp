#include "applying_rotation.h"

void applying_rotation(STLINFO &info_jaw, Matrix3f &mat, STLINFO &result_jaw) {

	for (unsigned int i = 0; i < info_jaw.num_of_triangle; i++) {
		Vector3f first, second, third;
		first  = { info_jaw.triangle[i].first.x, info_jaw.triangle[i].first.y, info_jaw.triangle[i].first.z };
		second = { info_jaw.triangle[i].second.x,info_jaw.triangle[i].second.y,info_jaw.triangle[i].second.z };
		third  = { info_jaw.triangle[i].third.x, info_jaw.triangle[i].third.y, info_jaw.triangle[i].third.z };
		
		Vector3f result_first, result_second, result_third;
		result_first  = mat * first;
		result_second = mat * second;
		result_third  = mat * third;
		
		result_jaw.triangle[i].first.x  = result_first.x();   result_jaw.triangle[i].first.y  = result_first.y();   result_jaw.triangle[i].first.z  = result_first.z();
		result_jaw.triangle[i].second.x = result_second.x();  result_jaw.triangle[i].second.y = result_second.y();  result_jaw.triangle[i].second.z = result_second.z();
		result_jaw.triangle[i].third.x  = result_third.x();   result_jaw.triangle[i].third.y  = result_third.y();   result_jaw.triangle[i].third.z  = result_third.z();
	}

}