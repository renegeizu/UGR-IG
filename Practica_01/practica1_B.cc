#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "objetos_B.h"

const int AXIS_SIZE=5000;

GLfloat Observer_distance, Observer_angle_x, Observer_angle_y;
GLfloat Window_width, Window_height, Front_plane, Back_plane;
int UI_window_pos_x = 50, UI_window_pos_y = 50, UI_window_width = 450, UI_window_height = 450;

_piramide piramide(0.85, 1.3);
_cubo cubo(0.2);

int modo = 0, figura = 0;

void clear_window(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void change_projection(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-Window_width, Window_width, -Window_height, Window_height, Front_plane, Back_plane);
}

void change_observer(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -Observer_distance);
	glRotatef(Observer_angle_x, 1, 0, 0);
	glRotatef(Observer_angle_y, 0, 1, 0);
}

void draw_axis(){
	glBegin(GL_LINES);
		glColor3f(1,0,0);
		glVertex3f(-AXIS_SIZE, 0, 0);
		glVertex3f(AXIS_SIZE, 0, 0);
		glColor3f(0, 1, 0);
		glVertex3f(0, -AXIS_SIZE, 0);
		glVertex3f(0, AXIS_SIZE, 0);
		glColor3f(0, 0, 1);
		glVertex3f(0, 0, -AXIS_SIZE);
		glVertex3f(0, 0, AXIS_SIZE);
	glEnd();
}

void draw_objects(){
	switch(opcion){
		case 0: // Modo Puntos
			if(figura == 0){ // Figura Piramide
				piramide.draw_puntos(1.0, 0.5, 0.0, 3);
			}else{ // Figura Cubo
				cubo.draw_puntos(1.0, 0.5, 0.0, 3);
			}
			break;
		case 1: // Modo Lineas
			if(figura == 0){ // Figura Piramide
				piramide.draw_aristas(1.0, 0.5, 0.0, 3);
			}else{ // Figura Cubo
				cubo.draw_aristas(1.0, 0.5, 0.0, 3);
			}
			break;
		case 2: // Modo Relleno
			if(figura == 0){ // Figura Piramide
				piramide.draw_solido(1.0, 0.5, 0.0);
			}else{ // Figura Cubo
				cubo.draw_solido(1.0, 0.5, 0.0);
			}
			break;
		case 3: // Modo Ajedrez
			if(figura == 0){ // Figura Piramide
				piramide.draw_solido_ajedrez(1.0, 0.5, 0.0, 0.0, 0.5, 1.0);
			}else{ // Figura Cubo
				cubo.draw_solido_ajedrez(1.0, 0.5, 0.0, 0.0, 0.5, 1.0);
			}
			break;
	}
}

void draw_scene(void){
	clear_window();
	change_observer();
	draw_axis();
	draw_objects();
	glutSwapBuffers();
}

void change_window_size(int Ancho1, int Alto1){
	change_projection();
	glViewport(0, 0, Ancho1, Alto1);
	glutPostRedisplay();
}

void normal_keys(unsigned char Tecla1, int x, int y){
	switch(toupper(Tecla1)){
		case 'Q':
			exit(0);
			break;
		case 'P':
			modo = 0; // Modo Puntos
			break;
		case 'L': // Modo Lineas
			modo = 1;
			break;
		case 'F': // Modo Relleno
			modo = 2;
			break;
		case 'C': // Modo Ajedrez
			modo = 3;
			break;
		case '1': // Figura Piramide
			figura = 0;
			break;
		case '2': // Figura Cubo
			figura = 1;
			break;
	}
}

void special_keys(int Tecla1, int x, int y){
	switch (Tecla1){
		case GLUT_KEY_LEFT:
			Observer_angle_y--;
			break;
		case GLUT_KEY_RIGHT:
			Observer_angle_y++;
			break;
		case GLUT_KEY_UP:
			Observer_angle_x--;
			break;
		case GLUT_KEY_DOWN:
			Observer_angle_x++;
			break;
		case GLUT_KEY_PAGE_UP:
			Observer_distance *= 1.2;
			break;
		case GLUT_KEY_PAGE_DOWN:
			Observer_distance /= 1.2;
			break;
	}
	glutPostRedisplay();
}

void initialize(void){
	Window_width = .5;
	Window_height = .5;
	Front_plane = 1;
	Back_plane = 1000;
	Observer_distance = 3*Front_plane;
	Observer_angle_x = 0;
	Observer_angle_y = 0;
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	change_projection();
	glViewport(0, 0, UI_window_width, UI_window_height);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(UI_window_pos_x, UI_window_pos_y);
	glutInitWindowSize(UI_window_width, UI_window_height);
	glutCreateWindow("Práctica 1");
	glutDisplayFunc(draw_scene);
    glutReshapeFunc(change_window_size);
    glutKeyboardFunc(normal_keys);
    glutSpecialFunc(special_keys);
	initialize();
	glutMainLoop();
    return 0;
}