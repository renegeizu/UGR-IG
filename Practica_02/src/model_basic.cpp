#include <model_basic.h>

Cubo::Cubo(float tam){
	vertices.resize(8);
	
	vertices[0].x = tam;			vertices[0].y = tam;			vertices[0].z = tam;
	vertices[1].x = tam;			vertices[1].y = tam;			vertices[1].z = -tam;
	vertices[2].x = tam;			vertices[2].y = -tam;		vertices[2].z = tam;
	vertices[3].x = tam;			vertices[3].y = -tam;		vertices[3].z = -tam;
	vertices[4].x = -tam;		vertices[4].y = tam;			vertices[4].z = tam;
	vertices[5].x = -tam;		vertices[5].y = tam;			vertices[5].z = -tam;
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

Piramide::Piramide(float tam, float al){
	vertices.resize(5); 
	
	vertices[0].x = -tam;	vertices[0].y = 0;		vertices[0].z = tam;
	vertices[1].x = tam;		vertices[1].y = 0;		vertices[1].z = tam;
	vertices[2].x = tam;		vertices[2].y = 0;		vertices[2].z = -tam;
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

Tetraedro::Tetraedro(float tam){
	vertices.resize(4); 
	
	vertices[0].x = -tam;	vertices[0].y = -tam;		vertices[0].z = tam;
	vertices[1].x = tam;		vertices[1].y = -tam;		vertices[1].z = tam;
	vertices[2].x = 0;		vertices[2].y = tam;			vertices[2].z = 0;
	vertices[3].x = 0;		vertices[3].y = -tam;		vertices[3].z = -tam;

	caras.resize(4);

	caras[0]._0 = 0;		caras[0]._1 = 1;		caras[0]._2 = 2;
	caras[1]._0 = 2;		caras[1]._1 = 1;		caras[1]._2 = 3;
	caras[2]._0 = 3;		caras[2]._1 = 0;		caras[2]._2 = 2;
	caras[3]._0 = 0;		caras[3]._1 = 3;		caras[3]._2 = 1;
}

Diamante::Diamante(float tam, float al){
	vertices.resize(6); 
	
	vertices[0].x = -tam;	vertices[0].y = 0;		vertices[0].z = tam;
	vertices[1].x = tam;		vertices[1].y = 0;		vertices[1].z = tam;
	vertices[2].x = tam;		vertices[2].y = 0;		vertices[2].z = -tam;
	vertices[3].x = -tam;	vertices[3].y = 0;		vertices[3].z = -tam;
	vertices[4].x = 0;		vertices[4].y = al;		vertices[4].z = 0;
	vertices[5].x = 0;		vertices[5].y = -al;		vertices[5].z = 0;

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
