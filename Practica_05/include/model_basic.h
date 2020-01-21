#ifndef MODEL_BASIC_H
#define MODEL_BASIC_H

#include <triangulos3D.h>

using namespace std;

class Cubo: public Triangulos3D{
	public:
		Cubo(float tam = 0.5);
};

class Piramide: public Triangulos3D{
	public:
		Piramide(float tam = 0.5, float al = 0.75);
};

class Tetraedro: public Triangulos3D{
	public:
		Tetraedro(float tam = 0.5);
};

class Diamante: public Triangulos3D{
	public:
		Diamante(float tam = 0.5, float al = 0.75);
		void setSelection(int selectTriangle);
		void resetSelection();
		void draw_solido_seleccion();
	private:
		bool seleccion[8] = {false, false, false, false, false, false, false, false};
};

#endif
