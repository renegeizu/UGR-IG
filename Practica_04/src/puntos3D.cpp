#include <puntos3D.h>

Puntos3D::Puntos3D(){
	
}

void Puntos3D::draw_puntos(float r, float g, float b, int grosor){
	int i;
	glPointSize(grosor);
	glColor3f(r, g, b);
	glBegin(GL_POINTS);
	for(i = 0; i < vertices.size(); i++){
		glVertex3fv((GLfloat *) &vertices[i]);
	}
	glEnd();
}
