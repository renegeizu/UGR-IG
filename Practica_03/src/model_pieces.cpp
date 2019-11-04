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

Cannon::Cannon(){
    vector<_vertex3f> perfil;
    _vertex3f aux;
    aux.x = 0.04;   aux.y = -0.4;   aux.z = 0.0;
    perfil.push_back(aux);
    aux.x = 0.04;   aux.y = 0.4;    aux.z = 0.0;
    perfil.push_back(aux);
    tubo_abierto.make_revolution(perfil, 12);
};

void Cannon::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
    glPushMatrix();
        glTranslatef(0.4, 0, 0);
        glRotatef(90.0, 0, 0, 1);
        tubo_abierto.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
    glPopMatrix();
}
