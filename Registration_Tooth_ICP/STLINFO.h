#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct xyz {
	float x;
	float y;
	float z;
};

class STLINFO {
public:
	vector<unsigned char> header;
	unsigned int num_of_triangle;  // header & num_of_triangle are just for completing format not for using
	int size_of_file;	  // size_of_file is just for saving

	vector<xyz> vec_norm;
	vector<xyz> xyz_jaw;
	vector<unsigned short> attribute_byte_count;

	STLINFO();
	void ready_for_spliting_foreach_triangle();
};