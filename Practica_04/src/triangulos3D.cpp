#include <triangulos3D.h>

Triangulos3D::Triangulos3D(){
	normales = false;	
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

void Triangulos3D::draw_normales_vertices(){
	calcular_normales();
    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
    for(unsigned int i = 0; i < normales_vertices.size(); i++){
        glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
        glVertex3f(vertices[i].x + normales_vertices[i].x * 0.1f, vertices[i].y + normales_vertices[i].y * 0.1f, vertices[i].z + normales_vertices[i].z * 0.1f);
    }
    glEnd();
}

void Triangulos3D::draw_normales_caras(){
	calcular_normales();
	glColor3f(0, 0, 1);
    glBegin(GL_LINES);
    int x = 0, y = 0, z = 0;
    for(unsigned int i = 0; i < normales_caras.size(); i++){
        x = (vertices[caras[i]._0].x + vertices[caras[i]._1].x + vertices[caras[i]._2].x)/3;
        y = (vertices[caras[i]._0].y + vertices[caras[i]._1].y + vertices[caras[i]._2].y)/3;
        z = (vertices[caras[i]._0].z + vertices[caras[i]._1].z + vertices[caras[i]._2].z)/3;
        glVertex3f(x + normales_caras[i].x, y + normales_caras[i].y, z + normales_caras[i].z);
        glVertex3f(x, y, z);
    }
    glEnd();
}

void Triangulos3D::draw_iluminacion_plana(){
	calcular_normales();
    glShadeModel(GL_FLAT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);
    for(unsigned int i = 0; i < caras.size(); i++){
        glNormal3f(normales_caras[i]._0, normales_caras[i]._1, normales_caras[i]._2);
        glVertex3f(vertices[caras[i]._0].x, vertices[caras[i]._0].y, vertices[caras[i]._0].z);
        glVertex3f(vertices[caras[i]._1].x, vertices[caras[i]._1].y, vertices[caras[i]._1].z);
        glVertex3f(vertices[caras[i]._2].x, vertices[caras[i]._2].y, vertices[caras[i]._2].z);
    }
    glEnd();
}

void Triangulos3D::draw_iluminacion_suave(){
	calcular_normales();
    glShadeModel(GL_SMOOTH);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    for(unsigned int i = 0; i < caras.size(); i++){
        glNormal3f(normales_vertices[caras[i]._0].x, normales_vertices[caras[i]._0].y, normales_vertices[caras[i]._0].z);
        glVertex3f(vertices[caras[i]._0].x, vertices[caras[i]._0].y, vertices[caras[i]._0].z);
        glNormal3f(normales_vertices[caras[i]._1].x, normales_vertices[caras[i]._1].y, normales_vertices[caras[i]._1].z);
        glVertex3f(vertices[caras[i]._1].x, vertices[caras[i]._1].y, vertices[caras[i]._1].z);
        glNormal3f(normales_vertices[caras[i]._2].x, normales_vertices[caras[i]._2].y, normales_vertices[caras[i]._2].z);
        glVertex3f(vertices[caras[i]._2].x, vertices[caras[i]._2].y, vertices[caras[i]._2].z);
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
		case SOLID_ILLUMINATED_FLAT:
			draw_iluminacion_plana();
			break;
		case SOLID_ILLUMINATED_GOURAUD:
			draw_iluminacion_suave();
			break;
	}
}	

void Triangulos3D::calcular_normales(){
	if(!normales){
        vector<int> auxiliar;
        auxiliar.resize(vertices.size());
        normales_vertices.resize(vertices.size());
        for(unsigned int i = 0; i < caras.size(); i++){
            //Normales Triangulos
            _vertex3f a = vertices[caras[i]._1] - vertices[caras[i]._0];
            _vertex3f b = vertices[caras[i]._2] - vertices[caras[i]._0];
            normales_caras.push_back((a.cross_product(b)).normalize());
            //Normales Vertices
            normales_vertices[caras[i]._0] += normales_caras[i];
            auxiliar[caras[i]._0]++;
            normales_vertices[caras[i]._1] += normales_caras[i];
            auxiliar[caras[i]._1]++;
            normales_vertices[caras[i]._2] += normales_caras[i];
            auxiliar[caras[i]._2]++;
        }
        for(unsigned int i = 0; i < normales_vertices.size(); i++){
            normales_vertices[i] /= auxiliar[i];
            normales_vertices[i].normalize();
        }
		normales = true;
    }
}