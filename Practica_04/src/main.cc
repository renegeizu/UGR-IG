#include <ctype.h>
#include <GL/glut.h>
#include <model_basic.h>
#include <model_hierarchical.h>
#include <model_light.h>
#include <model_material.h>
#include <model_ply.h>
#include <model_revolution.h>
#include <math.h>
#include <vector>

using namespace std;

typedef enum{CUBO, PIRAMIDE, OBJETO_PLY, CONO, PEON, ESFERA, CILINDRO, TETRAEDRO, DIAMANTE, TUBO, TANQUE, WATT} _tipo_objeto;
_tipo_objeto t_objeto = CUBO;
_modo modo = POINTS;

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

Light light_0 = Light(GL_LIGHT0, true, {1,1,1}, {0.5,0,0,1}, {1,0,0,1}, {1,1,1,1}); // Luz Direccional
Light light_1 = Light(GL_LIGHT1, false, {1,1,1}, {0.5,0,0,1}, {1,0,0,1}, {1,1,1,1}); // Luz No Direccional
bool light_0_state = false, light_1_state = false;
int light_0_pAngle = 0, light_0_nAngle = 0;

Material material_1 = Material({0.25,0,0,1}, {1,0,0,1}, {1,1,1,1}, 5);
Material material_2 = Material({0,0.25,0,1}, {0,1,0,1}, {1,1,1,1}, 7);
Material material_3 = Material({0,0,0.50,1}, {0,0,1,1}, {1,1,1,1}, 13);
Material material = material_1;
int choosenMaterial = 1;

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
	if(light_0_state){
		light_0.enable();
	}
	if(light_1_state){
		light_1.enable();
	}
	switch (t_objeto){
		case CUBO:
			cubo.setMaterial(material);
			cubo.draw(modo, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 2);
			break;
		case PIRAMIDE:
			piramide.setMaterial(material);
			piramide.draw(modo, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 2);
			break;
		case OBJETO_PLY:
			ply.setMaterial(material);
			ply.draw(modo, 1.0, 0.6, 0.0, 0.0, 1.0, 0.3, 2);
			break;
		case TETRAEDRO:
			tetraedro.setMaterial(material);
			tetraedro.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
			break;
		case DIAMANTE:
			diamante.setMaterial(material);
			diamante.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
			break;
		case CONO:
			revolution = cono;
			revolution.setMaterial(material);
			revolution.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
			break;
		case CILINDRO:
			revolution = cilindro;
			revolution.setMaterial(material);
			revolution.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
			break;
		case PEON:
			revolution = peon;
			revolution.setMaterial(material);
			revolution.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
			break;
		case ESFERA:
			revolution = esfera;
			revolution.setMaterial(material);
			revolution.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
			break;
		case TUBO:
			revolution = tubo;
			revolution.setMaterial(material);
			revolution.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
			break;
		case TANQUE:
			tanque.setMaterial(material);
			tanque.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
			break;
		case WATT:
			watt.setMaterial(material);
			watt.draw(modo, 0.2, 0.5, 1, 0.2, 0.7, 0.4, 2);
			break;
	}
	light_0.disable();
	light_1.disable();
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
		case 'Z':
			modo = SOLID_ILLUMINATED_FLAT;
			break;
		case 'X':
			modo = SOLID_ILLUMINATED_GOURAUD;
			break;
		case 'S':
			if(light_1_state)
				light_1_state = false;
			else
				light_1_state = true;
			break;
		case 'A':
			if(light_0_state)
				light_0_state = false;
			else
				light_0_state = true;
			break;
		case 'U':
			choosenMaterial++;
			if(choosenMaterial == 1){
				material = material_1;
			}else if(choosenMaterial == 2){
				material = material_2;
			}else if(choosenMaterial == 3){
				material = material_3;
			}else{
				choosenMaterial = 1;
				material = material_1;
			}
			break;
		case 'H':
			light_0_nAngle += 10;
			light_0.setPosition(_vertex3f(-sin(light_0_nAngle*M_PI/180), cos(light_0_nAngle*M_PI/180), cos(light_0_pAngle*M_PI/180)));
			break;
		case 'G':
			light_0_pAngle += 10;
			light_0.setPosition(_vertex3f(sin(light_0_pAngle*M_PI/180), cos(light_0_nAngle*M_PI/180), cos(light_0_pAngle*M_PI/180)));
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
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(Window_x, Window_y);
	glutInitWindowSize(Window_width, Window_high);
	glutCreateWindow("Practica 03");
	glutDisplayFunc(draw);
	glutReshapeFunc(change_window_size);
	glutKeyboardFunc(normal_key);
	glutSpecialFunc(special_key);
	initialize();
	ply.parametros(argv[1]);
	glutMainLoop();
	return 0;
}