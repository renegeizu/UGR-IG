#ifndef _READ_PLY
#define _READ_PLY

#include <assert.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

namespace _file_ply {
	void read( const char * nombreArchivo, vector<float> &Vertices,vector<int> &Faces );
} ;

#endif
