#include "load_stl_file.h"

void load_stl_file(const char * name, STLINFO & jaw)
{
	int size_of_file;
	
	FILE *fp = fopen(name, "rb");
	fseek(fp, 0, SEEK_END);
	size_of_file = ftell(fp);
	rewind(fp);

	fread(jaw.header.data(), sizeof(unsigned char), 80, fp);
	fread(&jaw.num_of_triangle, sizeof(unsigned int), 1, fp);
	printf("num_of_triangle = %d\n", jaw.num_of_triangle);
	
	jaw.ready_for_spliting_foreach_triangle();

	xyz vec_norm_xyz;
	xyz xyzxyzxyz[3];
	unsigned short attribute_byte_count_splited;

	float *normvec = new float[3];
	float *data = new float[9];
	unsigned short abc[1] = { 0 };

	for (unsigned int i = 0; i < jaw.num_of_triangle; i++) {
		rewind(fp);
		fseek(fp, 84, SEEK_SET);
		//fread(&vec_norm_xyz, sizeof(xyz), 1, fp);
		//fread(&xyzxyzxyz, sizeof(xyz), 3, fp);
		//fread(&attribute_byte_count_splited, sizeof(unsigned short), 1, fp);
		fread(normvec, sizeof(float), 3, fp);
		fread(data, sizeof(float), 9, fp);
		fread(abc, sizeof(unsigned short), 1, fp);

		printf("x = %f, y = %f, z = %f\n", normvec[0], normvec[1], normvec[2]);

		jaw.vec_norm.push_back(vec_norm_xyz);

		jaw.xyz_jaw.push_back(xyzxyzxyz[0]);
		jaw.xyz_jaw.push_back(xyzxyzxyz[1]);
		jaw.xyz_jaw.push_back(xyzxyzxyz[2]);

		jaw.attribute_byte_count.push_back(attribute_byte_count_splited);
	
	}
}
