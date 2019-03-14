#include "apply_alignment.h"

void apply_alignment(STLINFO &info_jaw, Matrix4f &mat_result_of_alignment) {

	for (unsigned int i = 0; i < info_jaw.num_of_triangle; i++) {
		Vector4f first, second, third;
		first  = { info_jaw.triangle[i].first.x, info_jaw.triangle[i].first.y, info_jaw.triangle[i].first.z,1 };
		second = { info_jaw.triangle[i].second.x,info_jaw.triangle[i].second.y,info_jaw.triangle[i].second.z,1 };
		third  = { info_jaw.triangle[i].third.x, info_jaw.triangle[i].third.y, info_jaw.triangle[i].third.z,1 };

		Vector4f result_first, result_second, result_third;
		result_first  = mat_result_of_alignment * first;
		result_second = mat_result_of_alignment * second;
		result_third  = mat_result_of_alignment * third;

		info_jaw.triangle[i].first.x = result_first.x();   info_jaw.triangle[i].first.y = result_first.y();   info_jaw.triangle[i].first.z = result_first.z();
		info_jaw.triangle[i].second.x = result_second.x();  info_jaw.triangle[i].second.y = result_second.y();  info_jaw.triangle[i].second.z = result_second.z();
		info_jaw.triangle[i].third.x = result_third.x();   info_jaw.triangle[i].third.y = result_third.y();   info_jaw.triangle[i].third.z = result_third.z();
	}

}