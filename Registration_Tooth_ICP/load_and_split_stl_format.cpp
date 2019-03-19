#include "load_and_split_stl_format.h"
/*
void get_avg_of_z(STLINFO &jaw, FILE *fp, float &avg) {
	
	XYZ vec_norm_read;
	TRIANGLE triangle_read;
	unsigned short attribute_byte_count_splited;

	float min_z = FLT_MAX;
	float max_z = -FLT_MAX;
	
	for (unsigned int i = 0; i < jaw.num_of_triangle; i++) {
		fread(&vec_norm_read, sizeof(XYZ), 1, fp);
		fread(&triangle_read, sizeof(TRIANGLE), 1, fp);
		fread(&attribute_byte_count_splited, sizeof(unsigned short), 1, fp);
		if (triangle_read.first.z > max_z) {
			max_z = triangle_read.first.z;
		}
		else if (triangle_read.first.z <= min_z) {
			min_z = triangle_read.first.z;
		}
		if (triangle_read.second.z > max_z) {
			max_z = triangle_read.second.z;
		}
		else if (triangle_read.second.z <= min_z) {
			min_z = triangle_read.second.z;
		}
		if (triangle_read.third.z > max_z) {
			max_z = triangle_read.third.z;
		}
		else if (triangle_read.third.z <= min_z) {
			min_z = triangle_read.third.z;
		}
	}

	avg = (min_z + max_z) / 2.0;
}

void load_and_split_stl_format(const char * name, STLINFO & jaw)
{
	FILE *fp = fopen(name, "rb");

	fread(jaw.header.data(), sizeof(unsigned char), 80, fp);
	fread(&jaw.num_of_triangle, sizeof(unsigned int), 1, fp);
	printf("num_of_triangle = %d\n", jaw.num_of_triangle);

	jaw.ready_for_spliting_foreach_triangle(); //secure capacity

	XYZ vec_norm_read;
	TRIANGLE triangle_read;
	unsigned short attribute_byte_count_splited;

	float avg_z;
	get_avg_of_z(jaw, fp, avg_z);

	//float min_z = FLT_MAX;
	//float max_z = -FLT_MAX;
	//for (unsigned int i = 0; i < jaw.num_of_triangle; i++) {
	//	fread(&vec_norm_read, sizeof(XYZ), 1, fp);
	//	fread(&triangle_read, sizeof(TRIANGLE), 1, fp);
	//	fread(&attribute_byte_count_splited, sizeof(unsigned short), 1, fp);
	//	if (triangle_read.first.z > max_z) {
	//		max_z = triangle_read.first.z;
	//	}
	//	else if (triangle_read.first.z <= min_z) {
	//		min_z = triangle_read.first.z;
	//	}
	//	if (triangle_read.second.z > max_z) {
	//		max_z = triangle_read.second.z;
	//	}
	//	else if (triangle_read.second.z <= min_z) {
	//		min_z = triangle_read.second.z;
	//	}
	//	if (triangle_read.third.z > max_z) {
	//		max_z = triangle_read.third.z;
	//	}
	//	else if (triangle_read.third.z <= min_z) {
	//		min_z = triangle_read.third.z;
	//	}
	//}

	rewind(fp);
	fseek(fp, 84, SEEK_SET);

	unsigned int cnt_larger_than_0 = 0;

	for (unsigned int i = 0, j = 0; i < jaw.num_of_triangle; i++) {

		fread(&vec_norm_read, sizeof(XYZ), 1, fp);
		fread(&triangle_read, sizeof(TRIANGLE), 1, fp);
		fread(&attribute_byte_count_splited, sizeof(unsigned short), 1, fp);

		if ( (triangle_read.first.z >= min_z + 1) & (triangle_read.second.z >= min_z + 1) & (triangle_read.third.z >= min_z + 1) ) {

			cnt_larger_than_0++;

			jaw.vec_norm.push_back(vec_norm_read);

			jaw.triangle.push_back(triangle_read);
			jaw.triangle[i].first = triangle_read.first;
			jaw.triangle[i].second = triangle_read.second;
			jaw.triangle[i].third = triangle_read.third;

			jaw.attribute_byte_count.push_back(attribute_byte_count_splited);

			// make each x, y, z vector for calculation covariance matrix
			jaw.X[j] = jaw.triangle[i].first.x;
			jaw.X[j + 1] = jaw.triangle[i].second.x;
			jaw.X[j + 2] = jaw.triangle[i].third.x;

			jaw.Y[j] = jaw.triangle[i].first.y;
			jaw.Y[j + 1] = jaw.triangle[i].second.y;
			jaw.Y[j + 2] = jaw.triangle[i].third.y;

			jaw.Z[j] = jaw.triangle[i].first.z;
			jaw.Z[j + 1] = jaw.triangle[i].second.z;
			jaw.Z[j + 2] = jaw.triangle[i].third.z;
			j += 3;
		}

		jaw.triangle2.push_back(triangle_read);
		jaw.triangle2[i].first = triangle_read.first;
		jaw.triangle2[i].second = triangle_read.second;
		jaw.triangle2[i].third = triangle_read.third;

		jaw.attribute_byte_count.push_back(attribute_byte_count_splited);

		// make each x, y, z vector for calculation covariance matrix
		jaw.X[j] = jaw.triangle[i].first.x;
		jaw.X[j + 1] = jaw.triangle[i].second.x;
		jaw.X[j + 2] = jaw.triangle[i].third.x;

		jaw.Y[j] = jaw.triangle[i].first.y;
		jaw.Y[j + 1] = jaw.triangle[i].second.y;
		jaw.Y[j + 2] = jaw.triangle[i].third.y;

		jaw.Z[j] = jaw.triangle[i].first.z;
		jaw.Z[j + 1] = jaw.triangle[i].second.z;
		jaw.Z[j + 2] = jaw.triangle[i].third.z;
		j += 3;
		
	}

	jaw.num_of_triangle = cnt_larger_than_0;

}
*/

void load_and_split_stl_format(const char * name, STLINFO & jaw)
{
	FILE *fp = fopen(name, "rb");

	fread(jaw.header.data(), sizeof(unsigned char), 80, fp);
	fread(&jaw.num_of_triangle, sizeof(unsigned int), 1, fp);
	printf("num_of_triangle = %d\n", jaw.num_of_triangle);
	
	jaw.ready_for_spliting_foreach_triangle(); //secure capacity

	XYZ vec_norm_read;
	TRIANGLE triangle_read;
	unsigned short attribute_byte_count_splited;

	for (unsigned int i = 0,  j = 0; i < jaw.num_of_triangle; i++) {

		fread(&vec_norm_read, sizeof(XYZ), 1, fp);
		fread(&triangle_read, sizeof(TRIANGLE), 1, fp);
		fread(&attribute_byte_count_splited, sizeof(unsigned short), 1, fp);

		jaw.vec_norm.push_back(vec_norm_read);

		jaw.triangle.push_back(triangle_read);
		jaw.triangle[i].first = triangle_read.first;
		jaw.triangle[i].second = triangle_read.second;
		jaw.triangle[i].third = triangle_read.third;

		jaw.attribute_byte_count.push_back(attribute_byte_count_splited);

		// make each x, y, z vector for calculation covariance matrix
		jaw.X[j    ] = jaw.triangle[i].first.x;
		jaw.X[j + 1] = jaw.triangle[i].second.x;
		jaw.X[j + 2] = jaw.triangle[i].third.x;

		jaw.Y[j    ] = jaw.triangle[i].first.y;
		jaw.Y[j + 1] = jaw.triangle[i].second.y;
		jaw.Y[j + 2] = jaw.triangle[i].third.y;

		jaw.Z[j    ] = jaw.triangle[i].first.z;
		jaw.Z[j + 1] = jaw.triangle[i].second.z;
		jaw.Z[j + 2] = jaw.triangle[i].third.z;
		j += 3;

	}
}