#include <model_hierarchical.h>

Tanque::Tanque(){
    giro_tubo = 2.0;
    giro_torreta = 0.0;
    giro_tubo_min = -9;
    giro_tubo_max = 20;
};

void Tanque::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
    glPushMatrix();
        chasis.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
        glRotatef(giro_torreta,0,1,0);
        glPushMatrix();
            glTranslatef(0.0,(chasis.altura+torreta.altura)/2.0,0.0);
            torreta.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(torreta.anchura/2.0,(chasis.altura+torreta.altura)/2.0,0.0);
            glRotatef(giro_tubo,0,0,1);
            tubo.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
        glPopMatrix();
    glPopMatrix();
};

Watt::Watt(){

}

void Watt::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){

}