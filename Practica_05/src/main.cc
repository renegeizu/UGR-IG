#include <ctype.h>
#include <GL/glut.h>
#include <model_basic.h>
#include <model_hierarchical.h>
#include <model_ply.h>
#include <model_revolution.h>
#include <math.h>
#include <vector>

using namespace std;

typedef enum{CUBO, PIRAMIDE, OBJETO_PLY, CONO, PEON, ESFERA, CILINDRO, TETRAEDRO, DIAMANTE, TUBO, TANQUE, WATT} _tipo_objeto;
_tipo_objeto t_objeto = WATT;
_modo modo = SOLID;

GLfloat Observer_distance, Observer_angle_x, Observer_angle_y;
GLfloat Size_x, Size_y, Front_plane, Back_plane;
int Window_x = 50, Window_y = 50, Window_width = 450, Window_high = 450;

float angle = 45;
float giro = 0;

Piramide piramide(0.85, 1.3);
Cubo cubo(0.2);
Tetraedro tetraedro(0.2);
Diamante diamante(0.85, 1.3);
ModelPly ply;
Cilindro cilindro;
Cono cono;
Peon peon;
Esfera esfera;
Tubo tubo;
Revolution revolution = cilindro;
Tanque tanque;
Watt watt;

int Ancho = 450, Alto = 450;
float factor = 1.0;
int estadoRaton[3], xc, yc;
bool change_view = false;
bool color_selection = false;

void clean_window(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void change_projection(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-Size_x, Size_x, -Size_y, Size_y, Front_plane, Back_plane);
}

void change_projection_alternative(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -100, 100);
}

void change_observer(){
	change_projection();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0, 0, Ancho,Alto);
	glTranslatef(0, 0, -Observer_distance);
	glRotatef(Observer_angle_x, 1, 0, 0);
	glRotatef(Observer_angle_y, 0, 1, 0);
}

void change_observer_alzado(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport((GLint) Ancho/2.0, 0, (GLint) Ancho/2.0, (GLint) Alto/2.0);
	glRotatef(90, 0, 1, 0);
	glScalef(1.0, factor, factor);
}

void change_observer_perfil(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0, (GLint) Alto/2.0, (GLint) Ancho/2.0, (GLint) Alto/2.0);
	glRotatef(90, 1, 0, 0);
	glScalef(factor, 1.0, factor);
}

void change_observer_planta(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0, 0, (GLint) Ancho/2.0, (GLint) Alto/2.0);
	glScalef(factor, factor, 1.0);
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
	if(!color_selection){
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
			case TETRAEDRO:
				tetraedro.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
				break;
			case DIAMANTE:
				diamante.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
				break;
			case CONO:
				revolution = cono;
				revolution.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
				break;
			case CILINDRO:
				revolution = cilindro;
				revolution.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
				break;
			case PEON:
				revolution = peon;
				revolution.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
				break;
			case ESFERA:
				revolution = esfera;
				revolution.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
				break;
			case TUBO:
				revolution = tubo;
				revolution.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
				break;
			case TANQUE:
				tanque.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
				break;
			case WATT:
				watt.draw(SOLID, 1, 0.5, 1, 0.2, 0.7, 0.4, 2);
				break;
		}
	}else{
		watt.draw(SOLID, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
	}
}

void draw(void){
	clean_window();
	if(change_view == false){
    	change_observer();
    	draw_axis();
    	draw_objects();
	}else{
		change_projection_alternative();
		change_observer_alzado();
		draw_axis();
		draw_objects();
		change_projection_alternative();
		change_observer_perfil();
		draw_axis();
		draw_objects();
		change_projection_alternative();
		change_observer_planta();
		draw_axis();
		draw_objects();
	}
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
		case 'P':
			modo = POINTS;
			break;
		case 'L':
			modo = EDGES;
			break;
		case 'F':
			modo = SOLID;
			break;
		case 'C':
			modo = SOLID_CHESS;
			break;
		case 'B':
			t_objeto = WATT;
            watt.setAngle((angle < 81) ? ++angle : angle = 81);
			break;
		case 'N':
			t_objeto = WATT;
            watt.setAngle((angle > 9) ? --angle : angle = 9);
			break;
		case 'M':
			t_objeto = WATT;
			giro += 2*angle*M_PI/90;
    		if(giro >= 360)
        		giro -= 360;
            watt.setSpin(giro);
			break;
		case '1':
			t_objeto = PIRAMIDE;
			break;
		case '2':
			t_objeto = CUBO;
			break;
		case '3':
			t_objeto = CONO;
			break;
		case '4':
			t_objeto = CILINDRO;
			break;
		case '5':
			t_objeto = ESFERA;
			break;
		case '6':
			t_objeto = OBJETO_PLY;
			break;
		case '7':
			t_objeto = TETRAEDRO;
			break;
		case '8':
			t_objeto = DIAMANTE;
			break;
		case '9':
			t_objeto = PEON;
			break;
		case '0':
			t_objeto = TUBO;
			break;
		case 'T':
			t_objeto = TANQUE;
			break;
		case 'W':
			t_objeto = WATT;
			break;
		case 'V':
			if(change_view){
				change_view = false;
			}else{
				change_view = true;
			}
			break;
		case '+':
			factor *= 0.9;
			break;
		case '-':
			factor *= 1.1;
			break;
		case 'S':
			if(color_selection){
				color_selection = false;
			}else{
				color_selection = true;
			}
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

void procesar_color(unsigned char color[3]){
	if(t_objeto == WATT){
		if(color[2] == 255){
			if(color[0] == 128){
				watt.unselectPiece(1);
			}else{
				watt.selectPiece(1);
			}
		}else if(color[2] == 254){
			if(color[0] == 128){
				watt.unselectPiece(2);
			}else{
				watt.selectPiece(2);
			}
		}else if(color[2] == 253){
			if(color[0] == 128){
				watt.unselectPiece(3);
			}else{
				watt.selectPiece(3);
			}
		}
	}
}

void pick_color(int x, int y){
	GLint viewport[4];
	unsigned char pixel[3];
	glGetIntegerv(GL_VIEWPORT, viewport);
	glReadBuffer(GL_BACK);
	glReadPixels(x, viewport[3]-y, 1, 1, GL_RGB,GL_UNSIGNED_BYTE, (GLubyte *) &pixel[0]);
	printf("Valor 'X' %d, Valor 'Y' %d, Color (%d, %d, %d) \n", x, y, pixel[0], pixel[1], pixel[2]);
	procesar_color(pixel);
	glutPostRedisplay();
}

void mouse_click(int boton, int estado, int x, int y){
	if(boton == GLUT_RIGHT_BUTTON) {
		if( estado == GLUT_DOWN) {
			estadoRaton[2] = 1;
			xc = x;
			yc = y;
		}else{
			estadoRaton[2] = 1;
		}
	}
	if(boton == GLUT_LEFT_BUTTON){
		if(estado == GLUT_DOWN){
			estadoRaton[2] = 2;
			xc = x;
			yc = y;
			pick_color(xc, yc);
		}
	}
}

void getCamara (GLfloat *x, GLfloat *y){
	*x = Observer_angle_x;
	*y = Observer_angle_y;
}

void setCamara (GLfloat x, GLfloat y){
	Observer_angle_x = x;
	Observer_angle_y = y;
}

void mouse_move(int x, int y){
	float x0, y0, xn, yn; 
	if(estadoRaton[2] == 1){
		getCamara(&x0, &y0);
		yn = y0+(y-yc);
		xn = x0-(x-xc);
		setCamara(xn, yn);
		xc = x;
		yc = y;
		glutPostRedisplay();
	}
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
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(Window_x, Window_y);
	glutInitWindowSize(Window_width, Window_high);
	glutCreateWindow("Practica 05");
	glutDisplayFunc(draw);
	glutReshapeFunc(change_window_size);
	glutKeyboardFunc(normal_key);
	glutSpecialFunc(special_key);
	glutMouseFunc(mouse_click);
    glutMotionFunc(mouse_move);
	initialize();
	ply.parametros(argv[1]);
	glutMainLoop();
	return 0;
}