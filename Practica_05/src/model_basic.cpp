#include <model_basic.h>

Cubo::Cubo(float tam){
	vertices.resize(8);
	
	vertices[0].x = tam;		vertices[0].y = tam;		vertices[0].z = tam;
	vertices[1].x = tam;		vertices[1].y = tam;		vertices[1].z = -tam;
	vertices[2].x = tam;		vertices[2].y = -tam;		vertices[2].z = tam;
	vertices[3].x = tam;		vertices[3].y = -tam;		vertices[3].z = -tam;
	vertices[4].x = -tam;		vertices[4].y = tam;		vertices[4].z = tam;
	vertices[5].x = -tam;		vertices[5].y = tam;		vertices[5].z = -tam;
	vertices[6].x = -tam;		vertices[6].y = -tam;		vertices[6].z = tam;
	vertices[7].x = -tam;		vertices[7].y = -tam;		vertices[7].z = -tam;
	
	caras.resize(12);
	
	caras[0]._0 = 4;			caras[0]._1 = 6;			caras[0]._2 = 2;
	caras[1]._0 = 2;			caras[1]._1 = 0;			caras[1]._2 = 4;
	caras[2]._0 = 0;			caras[2]._1 = 2;			caras[2]._2 = 3;
	caras[3]._0 = 3;			caras[3]._1 = 1;			caras[3]._2 = 0;
	caras[4]._0 = 1;			caras[4]._1 = 3;			caras[4]._2 = 7;
	caras[5]._0 = 7;			caras[5]._1 = 5;			caras[5]._2 = 1;
	caras[6]._0 = 5;			caras[6]._1 = 7;			caras[6]._2 = 6;
	caras[7]._0 = 6;			caras[7]._1 = 4;			caras[7]._2 = 5;
	caras[8]._0 = 5;			caras[8]._1 = 4;			caras[8]._2 = 0;
	caras[9]._0 = 0;			caras[9]._1 = 1;			caras[9]._2 = 5;
	caras[10]._0 = 6;			caras[10]._1 = 7;			caras[10]._2 = 3;
	caras[11]._0 = 3;			caras[11]._1 = 2;			caras[11]._2 = 6;
}

void Cubo::setSelection(int selectTriangle){
	if(selectTriangle >= 0 && selectTriangle < caras.size()){
		seleccion[selectTriangle] = !seleccion[selectTriangle];
	}
}

void Cubo::resetSelection(){
	for(int i = 0; i < caras.size(); i++){
		seleccion[i] = false;
	}
}

void Cubo::draw_solido_seleccion(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	float b = 0.0;
	for(int i = 0; i < caras.size(); i++){
		if(seleccion[i]){
			glColor3f(0.1, b, 0.1);
		}else{
			glColor3f(0.6, b, 0.6);
		}
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
		b += 0.005;
	}
	glEnd();
}

Piramide::Piramide(float tam, float al){
	vertices.resize(5); 
	
	vertices[0].x = -tam;	vertices[0].y = 0;		vertices[0].z = tam;
	vertices[1].x = tam;	vertices[1].y = 0;		vertices[1].z = tam;
	vertices[2].x = tam;	vertices[2].y = 0;		vertices[2].z = -tam;
	vertices[3].x = -tam;	vertices[3].y = 0;		vertices[3].z = -tam;
	vertices[4].x = 0;		vertices[4].y = al;		vertices[4].z = 0;

	caras.resize(6);

	caras[0]._0 = 0;		caras[0]._1 = 1;		caras[0]._2 = 4;
	caras[1]._0 = 1;		caras[1]._1 = 2;		caras[1]._2 = 4;
	caras[2]._0 = 2;		caras[2]._1 = 3;		caras[2]._2 = 4;
	caras[3]._0 = 3;		caras[3]._1 = 0;		caras[3]._2 = 4;
	caras[4]._0 = 3;		caras[4]._1 = 1;		caras[4]._2 = 0;
	caras[5]._0 = 3;		caras[5]._1 = 2;		caras[5]._2 = 1;
}

void Piramide::setSelection(int selectTriangle){
	if(selectTriangle >= 0 && selectTriangle < caras.size()){
		seleccion[selectTriangle] = !seleccion[selectTriangle];
	}
}

void Piramide::resetSelection(){
	for(int i = 0; i < caras.size(); i++){
		seleccion[i] = false;
	}
}

void Piramide::draw_solido_seleccion(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	float b = 0.0;
	for(int i = 0; i < caras.size(); i++){
		if(seleccion[i]){
			glColor3f(0.2, b, 0.2);
		}else{
			glColor3f(0.7, b, 0.7);
		}
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
		b += 0.005;
	}
	glEnd();
}

Tetraedro::Tetraedro(float tam){
	vertices.resize(4); 
	
	vertices[0].x = -tam;	vertices[0].y = -tam;		vertices[0].z = tam;
	vertices[1].x = tam;	vertices[1].y = -tam;		vertices[1].z = tam;
	vertices[2].x = 0;		vertices[2].y = tam;		vertices[2].z = 0;
	vertices[3].x = 0;		vertices[3].y = -tam;		vertices[3].z = -tam;

	caras.resize(4);

	caras[0]._0 = 0;		caras[0]._1 = 1;		caras[0]._2 = 2;
	caras[1]._0 = 2;		caras[1]._1 = 1;		caras[1]._2 = 3;
	caras[2]._0 = 3;		caras[2]._1 = 0;		caras[2]._2 = 2;
	caras[3]._0 = 0;		caras[3]._1 = 3;		caras[3]._2 = 1;
}

void Tetraedro::setSelection(int selectTriangle){
	if(selectTriangle >= 0 && selectTriangle < caras.size()){
		seleccion[selectTriangle] = !seleccion[selectTriangle];
	}
}

void Tetraedro::resetSelection(){
	for(int i = 0; i < caras.size(); i++){
		seleccion[i] = false;
	}
}

void Tetraedro::draw_solido_seleccion(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	float b = 0.0;
	for(int i = 0; i < caras.size(); i++){
		if(seleccion[i]){
			glColor3f(0.3, b, 0.3);
		}else{
			glColor3f(0.8, b, 0.8);
		}
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
		b += 0.005;
	}
	glEnd();
}

Diamante::Diamante(float tam, float al){
	vertices.resize(6); 
	
	vertices[0].x = -tam;	vertices[0].y = 0;		vertices[0].z = tam;
	vertices[1].x = tam;	vertices[1].y = 0;		vertices[1].z = tam;
	vertices[2].x = tam;	vertices[2].y = 0;		vertices[2].z = -tam;
	vertices[3].x = -tam;	vertices[3].y = 0;		vertices[3].z = -tam;
	vertices[4].x = 0;		vertices[4].y = al;		vertices[4].z = 0;
	vertices[5].x = 0;		vertices[5].y = -al;	vertices[5].z = 0;

	caras.resize(8);

	caras[0]._0 = 0;		caras[0]._1 = 1;		caras[0]._2 = 4;
	caras[1]._0 = 1;		caras[1]._1 = 2;		caras[1]._2 = 4;
	caras[2]._0 = 2;		caras[2]._1 = 3;		caras[2]._2 = 4;
	caras[3]._0 = 3;		caras[3]._1 = 0;		caras[3]._2 = 4;
	caras[4]._0 = 3;		caras[4]._1 = 0;		caras[4]._2 = 5;
	caras[5]._0 = 2;		caras[5]._1 = 3;		caras[5]._2 = 5;
	caras[6]._0 = 1;		caras[6]._1 = 2;		caras[6]._2 = 5;
	caras[7]._0 = 0;		caras[7]._1 = 1;		caras[7]._2 = 5;
}

void Diamante::setSelection(int selectTriangle){
	if(selectTriangle >= 0 && selectTriangle < caras.size()){
		seleccion[selectTriangle] = !seleccion[selectTriangle];
	}
}

void Diamante::resetSelection(){
	for(int i = 0; i < caras.size(); i++){
		seleccion[i] = false;
	}
}

void Diamante::draw_solido_seleccion(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	float b = 0.0;
	for(int i = 0; i < caras.size(); i++){
		if(seleccion[i]){
			glColor3f(0.4, b, 0.4);
		}else{
			glColor3f(0.9, b, 0.9);
		}
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
		b += 0.005;
	}
	glEnd();
}