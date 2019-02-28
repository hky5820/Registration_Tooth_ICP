#include "load_and_split_stl_format.h"

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

		// for calculation covariance matrix
		jaw.X[j]     = jaw.triangle[i].first.x;
		jaw.X[j + 1] = jaw.triangle[i].second.x;
		jaw.X[j + 2] = jaw.triangle[i].third.x;

		jaw.Y[j]     = jaw.triangle[i].first.y;
		jaw.Y[j + 1] = jaw.triangle[i].second.y;
		jaw.Y[j + 2] = jaw.triangle[i].third.y;

		jaw.Z[j]     = jaw.triangle[i].first.z;
		jaw.Z[j + 1] = jaw.triangle[i].second.z;
		jaw.Z[j + 2] = jaw.triangle[i].third.z;
		j += 3;
	}
}