#include <ctype.h>
#include <GL/glut.h>
#include <model_basic.h>
#include <model_ply.h>
#include <model_revolution.h>
#include <math.h>
#include <vector>

using namespace std;

typedef enum{CUBO, PIRAMIDE, OBJETO_PLY, ROTACION} _tipo_objeto;
_tipo_objeto t_objeto = CUBO;
_modo modo = POINTS;

GLfloat Observer_distance, Observer_angle_x, Observer_angle_y;
GLfloat Size_x, Size_y, Front_plane, Back_plane;
int Window_x = 50, Window_y = 50, Window_width = 450, Window_high = 450;

Cubo cubo;
Piramide piramide(0.85, 1.3);
ModelPly ply;
Revolution rotacion;

void clean_window(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void change_projection(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-Size_x, Size_x, -Size_y, Size_y, Front_plane, Back_plane);
}

void change_observer(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -Observer_distance);
	glRotatef(Observer_angle_x, 1, 0, 0);
	glRotatef(Observer_angle_y, 0, 1, 0);
}

void draw_axis(){
	glDisable(GL_LIGHTING);
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
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
	switch (t_objeto){
		case CUBO:
			cubo.draw(modo, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 2);
			break;
		case PIRAMIDE:
			piramide.draw(modo, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 2);
			break;
		case OBJETO_PLY:
			ply.draw(modo, 1.0, 0.6, 0.0, 0.0, 1.0, 0.3, 2);
			break;
		case ROTACION:
			rotacion.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
			break;
	}
}

void draw(void){
	clean_window();
	change_observer();
	draw_axis();
	draw_objects();
	glutSwapBuffers();
}

void change_window_size(int Ancho1, int Alto1){
	float Aspect_ratio;
	Aspect_ratio = (float)Alto1 / (float)Ancho1;
	Size_y = Size_x * Aspect_ratio;
	change_projection();
	glViewport(0, 0, Ancho1, Alto1);
	glutPostRedisplay();
}

void normal_key(unsigned char Tecla1, int x, int y){
	switch(toupper(Tecla1)){
		case 'Q':
			exit(0);
		case '1':
			modo = POINTS;
			break;
		case '2':
			modo = EDGES;
			break;
		case '3':
			modo = SOLID;
			break;
		case '4':
			modo = SOLID_CHESS;
			break;
		case 'P':
			t_objeto = PIRAMIDE;
			break;
		case 'C':
			t_objeto = CUBO;
			break;
		case 'O':
			t_objeto = OBJETO_PLY;
			break;
		case 'R':
			t_objeto = ROTACION;
			break;
	}
	glutPostRedisplay();
}

void special_key(int Tecla1, int x, int y){
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
	Size_x = 0.5;
	Size_y = 0.5;
	Front_plane = 1;
	Back_plane = 1000;
	Observer_distance = 4 * Front_plane;
	Observer_angle_x = 0;
	Observer_angle_y = 0;
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	change_projection();
	glViewport(0, 0, Window_width, Window_high);
}

int main(int argc, char *argv[]){
	vector<_vertex3f> perfil2;
	_vertex3f aux;
	aux.x = 1.0;
	aux.y = -1.0;
	aux.z = 0.0;
	perfil2.push_back(aux);
	aux.x = 1.0;
	aux.y = 1.0;
	aux.z = 0.0;
	perfil2.push_back(aux);
	rotacion.parametros(perfil2, 6);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(Window_x, Window_y);
	glutInitWindowSize(Window_width, Window_high);
	glutCreateWindow("PRACTICA - 2");
	glutDisplayFunc(draw);
	glutReshapeFunc(change_window_size);
	glutKeyboardFunc(normal_key);
	glutSpecialFunc(special_key);
	initialize();
	ply.parametros(argv[1]);
	glutMainLoop();
	return 0;
}