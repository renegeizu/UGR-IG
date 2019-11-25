#include <model_pieces.h>

TanqueChasis::TanqueChasis(){
    vector<_vertex3f> perfil;
    _vertex3f aux;
    aux.x = 0.0;    aux.y = -0.5;   aux.z = 0.0;
    perfil.push_back(aux);
    aux.x = 0.107;  aux.y = -0.5;   aux.z = 0.0;
    perfil.push_back(aux);
    aux.x = 0.107;  aux.y = 0.5;    aux.z = 0.0;
    perfil.push_back(aux);
    aux.x = 0.0;    aux.y = 0.5;    aux.z = 0.0;
    perfil.push_back(aux);
    rodamiento.make_revolution(perfil, 12);
    altura = 0.22;
};

void TanqueChasis::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
    glPushMatrix();
        glScalef(1.0, 0.22, 0.95);
        base.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
    glPushMatrix();
        glRotatef(90.0, 1, 0, 0);
        rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.25, 0.0, 0.0);
        glRotatef(90.0, 1, 0, 0);
        rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.5, 0.0, 0.0);
        glRotatef(90.0, 1, 0, 0);
        rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.25, 0.0, 0.0);
        glRotatef(90.0, 1, 0, 0);
        rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.5, 0.0, 0.0);
        glRotatef(90.0, 1, 0, 0);
        rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
}

TanqueTorreta::TanqueTorreta(){
    altura = 0.18;
    anchura = 0.65;
};

void TanqueTorreta::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
    glPushMatrix();
        glScalef(0.65, 0.18, 0.6);
        base.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.325, 0, 0);
        glRotatef(90.0, 0, 0, 1);
        glScalef(0.18, 0.16, 0.6);
        parte_trasera.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
}

TanqueCannon::TanqueCannon(){
    vector<_vertex3f> perfil;
    _vertex3f aux;
    aux.x = 0.04;   aux.y = -0.4;   aux.z = 0.0;
    perfil.push_back(aux);
    aux.x = 0.04;   aux.y = 0.4;    aux.z = 0.0;
    perfil.push_back(aux);
    tubo_abierto.make_revolution(perfil, 12);
};

void TanqueCannon::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
    glPushMatrix();
        glTranslatef(0.4, 0, 0);
        glRotatef(90.0, 0, 0, 1);
        tubo_abierto.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
}

WattBola::WattBola(){
    angZ = ANGLE;
    objPly.parametros("data/beethoven");
}

WattBola::WattBola(float angle){
    angZ = angle;
    objPly.parametros("data/beethoven");
}

void WattBola::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0, -RADIO/2, 0);
        glRotatef(ANGAPERTURA, 0, 0, 1);
        glScalef(TAMPLY, TAMPLY, TAMPLY);
        objPly.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0, RADIO, 0);
        glScalef(RADIO, RADIO, RADIO);
        esfera.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
}

void WattBola::setAngle(float angle){
    angZ = angle;
}

WattLanza::WattLanza(){
    angZ = ANGLE;
}

WattLanza::WattLanza(float angle){
    angZ = angle;
}

void WattLanza::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0, TAMLARGO/2, 0);
        glScalef(TAM, TAMLARGO, TAM);
        cilindro.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
}

void WattLanza::setAngle(float angle){
    angZ = angle;
}

WattTransversal::WattTransversal(){
    angZ = ANGLE;
}

WattTransversal::WattTransversal(float angle){
    angZ = angle;
}

void WattTransversal::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0, TAMBRAZO/2, 0);
        glScalef(TAMANCHO, TAMBRAZO, TAMANCHO);
        cilindro.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
}

void WattTransversal::setAngle(float angle){
    angZ = angle;
}

WattBrazo::WattBrazo(){
    angZ = ANGLE;
}

WattBrazo::WattBrazo(float angle){
    angZ = angle;
}

void WattBrazo::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
    bola.setAngle(angZ);
    lanza.setAngle(angZ);
    transversal.setAngle(angZ);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix(); //Bola
        bola.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
    glPushMatrix(); //Lanza
        glTranslatef(0, DIAMETRO-0.02, 0);
        lanza.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
    glPushMatrix(); //Transversal
        glTranslatef(0, (TAMLARGO+DIAMETRO)/2, 0);
        glRotatef(ANGAPERTURA-angZ*2, 0, 0, 1);
        transversal.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
}

void WattBrazo::setAngle(float angle){
    angZ = angle;
}

WattCaja::WattCaja(){
    angZ = ANGLE;
}

WattCaja::WattCaja(float angle){
    angZ = angle;
}

void WattCaja::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0, RADIO/2, 0);
        glScalef(RADIO, RADIO, RADIO);
        cilindro.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
}

void WattCaja::setAngle(float angle){
    angZ = angle;
}

WattCuerpo::WattCuerpo(){
    angZ = ANGLE;
}

WattCuerpo::WattCuerpo(float angle){
    angZ = angle;
}

void WattCuerpo::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
    caja.setAngle(angZ);
    brazo.setAngle(angZ);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix(); //Caja Arriba
        glTranslatef(0, cos(angZ*M_PI/180.0)*(TAMLARGO+DIAMETRO)-RADIO/4, 0);
        caja.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
    glPushMatrix(); //Brazo Izquierdo
        glTranslatef(-(sin(angZ*M_PI/180.0)*(TAMLARGO+DIAMETRO))-RADIO/3, RADIO/2, 0);
        glRotatef(-angZ, 0, 0, 1);
        glRotatef(ANGAPERTURA, 0, 1, 0);
        brazo.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
    glPushMatrix(); //Brazo Derecho
        glTranslatef((sin(angZ*M_PI/180.0)*(TAMLARGO+DIAMETRO))+RADIO/3, RADIO/2, 0);
        glRotatef(angZ, 0, 0, 1);
        brazo.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
    glPushMatrix(); //Brazo Atras
        glTranslatef(0, RADIO/2, -(sin(angZ*M_PI/180.0)*(TAMLARGO+DIAMETRO))-RADIO/3);
        glRotatef(angZ, 1, 0, 0);
        glRotatef(ANGAPERTURA/2, 0, 1, 0);
        brazo.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
    glPushMatrix(); //Brazo Frente
        glTranslatef(0, RADIO/2, (sin(angZ*M_PI/180.0)*(TAMLARGO+DIAMETRO))+RADIO/3);
        glRotatef(-angZ, 1, 0, 0);
        glRotatef(-ANGAPERTURA/2, 0, 1, 0);
        brazo.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
    glPushMatrix(); //Caja Abajo
        caja.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
}

void WattCuerpo::setAngle(float angle){
    angZ = angle;
}

WattColumna::WattColumna(){
    angZ = ANGLE;
}

WattColumna::WattColumna(float angle){
    angZ = angle;
}

void WattColumna::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0, TAMFIGURA/2+0.1, 0);
        glScalef(RADIO/2, TAMFIGURA, RADIO/2);
        cilindro.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
}

void WattColumna::setAngle(float angle){
    angZ = angle;
}

WattBase::WattBase(){
    angZ = ANGLE;
}

WattBase::WattBase(float angle){
    angZ = angle;
}

void WattBase::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0, RADIO/4, 0);
        glScalef(TAMLARGO, RADIO/4, TAMLARGO);
        cubo.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
}

void WattBase::setAngle(float angle){
    angZ = angle;
}