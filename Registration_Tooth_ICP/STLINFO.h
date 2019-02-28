#pragma once
#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

struct XYZ {
	float x;
	float y;
	float z;

	XYZ() {};
	XYZ(float num_init) {
		x = num_init;
		y = num_init;
		z = num_init;
	};
};

struct TRIANGLE {
	XYZ first;
	XYZ second;
	XYZ third;
};

class STLINFO {
public:
	// stl format - header / num_of_triangle / vec_norm / triangle / attribute_byte_count
	vector<unsigned char> header;
	unsigned int num_of_triangle;  // header & num_of_triangle are just for completing format not for using
	vector<XYZ> vec_norm;
	vector<TRIANGLE> triangle;
	vector<unsigned short> attribute_byte_count;

	XYZ average_xyz; // for PCA

	// for calculation covariance matrix
	vector<float> X;
	vector<float> Y;
	vector<float> Z; 

	STLINFO();
	void ready_for_spliting_foreach_triangle();
};