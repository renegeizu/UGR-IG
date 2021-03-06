#ifndef TRIANGULOS3D_H
#define TRIANGULOS3D_H

#include <puntos3D.h>

using namespace std;

typedef enum{POINTS,EDGES,SOLID_CHESS,SOLID} _modo;

class Triangulos3D: public Puntos3D{
	public:
		Triangulos3D();
		void draw_aristas(float r, float g, float b, int grosor);
		void draw_solido(float r, float g, float b);
		void draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
		void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
		vector<_vertex3i> caras;
};

#endif
