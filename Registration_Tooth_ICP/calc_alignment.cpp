#include "calc_alignment.h"

float calc_mat_element(vector<float> &param1, vector<float> &param2, float avg1, float avg2) {

	float sum = 0;
	size_t size = param1.size();
	for (int i = 0; i < size; i++) {
		sum += (param1[i] - avg1) * (param2[i] - avg2);
	}

	return sum;
}

void calc_mat_cross_covariance(vector<float> &vec_for_cross_cov_x1,
	vector<float> &vec_for_cross_cov_y1,
	vector<float> &vec_for_cross_cov_z1,
	vector<float> &vec_for_cross_cov_x2,
	vector<float> &vec_for_cross_cov_y2,
	vector<float> &vec_for_cross_cov_z2,
	XYZ avg1, XYZ avg2,
	Matrix3f &mat_cross_covariance) {

	mat_cross_covariance(0, 0) = calc_mat_element(vec_for_cross_cov_x1, vec_for_cross_cov_x2, avg1.x, avg2.x);
	mat_cross_covariance(0, 1) = calc_mat_element(vec_for_cross_cov_x1, vec_for_cross_cov_y2, avg1.x, avg2.y);
	mat_cross_covariance(0, 2) = calc_mat_element(vec_for_cross_cov_x1, vec_for_cross_cov_z2, avg1.x, avg2.z);
	mat_cross_covariance(1, 0) = calc_mat_element(vec_for_cross_cov_y1, vec_for_cross_cov_x2, avg1.y, avg2.x);
	mat_cross_covariance(1, 1) = calc_mat_element(vec_for_cross_cov_y1, vec_for_cross_cov_y2, avg1.y, avg2.y);
	mat_cross_covariance(1, 2) = calc_mat_element(vec_for_cross_cov_y1, vec_for_cross_cov_z2, avg1.y, avg2.z);
	mat_cross_covariance(2, 0) = calc_mat_element(vec_for_cross_cov_z1, vec_for_cross_cov_x2, avg1.z, avg2.x);
	mat_cross_covariance(2, 1) = calc_mat_element(vec_for_cross_cov_z1, vec_for_cross_cov_y2, avg1.z, avg2.y);
	mat_cross_covariance(2, 2) = calc_mat_element(vec_for_cross_cov_z1, vec_for_cross_cov_z2, avg1.z, avg2.z);
}

void calc_alignment(vector<pair<XYZ, XYZ>> &pair_closest_point, Matrix4f &mat_result_of_alignment) {

	// translation
	XYZ sum1(0.0), sum2(0.0), avg1, avg2;
	size_t size = pair_closest_point.size();
	for (int i = 0; i < size; i++) {
		sum1.x += pair_closest_point[i].first.x;  sum1.y += pair_closest_point[i].first.y;  sum1.z += pair_closest_point[i].first.z;
		sum2.x += pair_closest_point[i].second.x; sum2.y += pair_closest_point[i].second.y; sum2.z += pair_closest_point[i].second.z;
	}

	avg1.x = sum1.x / (float)size; avg1.y = sum1.y / (float)size; avg1.z = sum1.z / (float)size;
	avg2.x = sum2.x / (float)size; avg2.y = sum2.y / (float)size; avg2.z = sum2.z / (float)size;	// calc_centroid

	mat_result_of_alignment(0, 3) = avg2.x - avg1.x;
	mat_result_of_alignment(1, 3) = avg2.y - avg1.y;
	mat_result_of_alignment(2, 3) = avg2.z - avg1.z;
	//cout << "trans x : " << avg2.x - avg1.x << "\n"; 
	//cout << "trans y : " << avg2.y - avg1.y << "\n";
	//cout << "trans z : " << avg2.z - avg1.z << "\n";

	// rotation
	vector<float> vec_for_cross_cov_x1, vec_for_cross_cov_y1, vec_for_cross_cov_z1, // pi - cs, qi - ct
				  vec_for_cross_cov_x2, vec_for_cross_cov_y2, vec_for_cross_cov_z2;
	for (int i = 0; i < size; i++) {
		vec_for_cross_cov_x1.push_back(pair_closest_point[i].first.x);
		vec_for_cross_cov_y1.push_back(pair_closest_point[i].first.y);
		vec_for_cross_cov_z1.push_back(pair_closest_point[i].first.z);
		vec_for_cross_cov_x2.push_back(pair_closest_point[i].second.x);
		vec_for_cross_cov_y2.push_back(pair_closest_point[i].second.y);
		vec_for_cross_cov_z2.push_back(pair_closest_point[i].second.z);
	}
	
	Matrix3f mat_cross_covariance;
	calc_mat_cross_covariance(vec_for_cross_cov_x1, 
		vec_for_cross_cov_y1, vec_for_cross_cov_z1,
		vec_for_cross_cov_x2, vec_for_cross_cov_y2, 
		vec_for_cross_cov_z2, avg1, avg2, 
		mat_cross_covariance);

	JacobiSVD<MatrixXf> svd(mat_cross_covariance, ComputeFullU | ComputeFullV);
	Matrix3f mat_rot = svd.matrixV() * svd.matrixU().transpose();
		
	mat_result_of_alignment.topLeftCorner(3, 3) = mat_rot;

}