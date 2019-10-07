#ifndef PUNTOS3D_H
#define PUNTOS3D_H

#include <GL/gl.h>
#include <stdlib.h>
#include <vector>
#include <vertex.h>

using namespace std;

const float AXIS_SIZE = 5000;

class Puntos3D{
	public:
		Puntos3D();
		void draw_puntos(float r, float g, float b, int grosor);
		vector<_vertex3f> vertices;
};

#endif
