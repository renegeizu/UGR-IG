#include <triangulos3D.h>

Triangulos3D::Triangulos3D(){
	
}

void Triangulos3D::draw_aristas(float r, float g, float b, int grosor){
	int i;
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(grosor);
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLES);
	for(i = 0; i < caras.size(); i++){
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
	glEnd();
}

void Triangulos3D::draw_solido(float r, float g, float b){
	int i;
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLES);
	for(i = 0; i < caras.size(); i++){
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
	glEnd();
}

void Triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2){
	int i;
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(r1, g1, b1);
	glBegin(GL_TRIANGLES);
	for(i = 0; i < caras.size(); i++){
		if(i % 2 == 0){
			glColor3f(r1, g1, b1);
		}else{
			glColor3f(r2, g2, b2);
		}
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
	glEnd();
}

void Triangulos3D::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
	switch (modo){
		case POINTS:
			draw_puntos(r1, g1, b1, grosor);
			break;
		case EDGES:
			draw_aristas(r1, g1, b1, grosor);
			break;
		case SOLID_CHESS:
			draw_solido_ajedrez(r1, g1, b1, r2, g2, b2);
			break;
		case SOLID:
			draw_solido(r1, g1, b1);
			break;
	}
}