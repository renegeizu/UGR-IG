#ifndef TRIANGULOS3D_H
#define TRIANGULOS3D_H

#include <puntos3D.h>

using namespace std;

typedef enum{POINTS, EDGES, SOLID_CHESS, SOLID, SOLID_ILLUMINATED_FLAT, SOLID_ILLUMINATED_GOURAUD} _modo;

class Triangulos3D: public Puntos3D{
	public:
		Triangulos3D();

		void draw_aristas(float r, float g, float b, int grosor);
		void draw_solido(float r, float g, float b);
		void draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
		void draw_normales_vertices();
		void draw_normales_caras();
		void draw_iluminacion_plana();
		void draw_iluminacion_suave();
		void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

		void calcular_normales();
		
		vector<_vertex3i> caras;
		vector<_vertex3f> normales_caras;
		vector<_vertex3f> normales_vertices;

		bool normales;

		_vertex4f ambiente_difusa;
		_vertex4f especular;
		float brillo;
};

#endif
