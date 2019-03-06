#define _CRT_SECURE_NO_WARNINGS
#include "stl_add_and_save.h"

void stl_add_and_save(const char * name, STLINFO & info_jaw1, STLINFO & info_jaw2){

	FILE *fp = fopen(name, "wb");
	if (fp == NULL) exit(0);

	fwrite(info_jaw1.header.data(), sizeof(unsigned char), 80, fp);

	unsigned int sum_num_of_triangle = info_jaw1.num_of_triangle + info_jaw2.num_of_triangle;
	fwrite(&sum_num_of_triangle, sizeof(unsigned int), 1, fp);

	for (unsigned int i = 0; i < info_jaw1.num_of_triangle; i++) {
		fwrite(&info_jaw1.vec_norm[i], sizeof(XYZ), 1, fp);
		fwrite(&info_jaw1.triangle[i], sizeof(TRIANGLE), 1, fp);
		fwrite(&info_jaw1.attribute_byte_count[i], sizeof(unsigned short), 1, fp);
	}
	for (unsigned int i = 0; i < info_jaw2.num_of_triangle; i++) {
		fwrite(&info_jaw2.vec_norm[i], sizeof(XYZ), 1, fp);
		fwrite(&info_jaw2.triangle[i], sizeof(TRIANGLE), 1, fp);
		fwrite(&info_jaw2.attribute_byte_count[i], sizeof(unsigned short), 1, fp);
	}

	fclose(fp);

}
