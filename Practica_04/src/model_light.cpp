#include <model_light.h>

Light::Light(){

}

Light::Light(const GLenum &_id, const bool &_directional, const _vertex3f &_position, const _vertex4f &_ambiental, const _vertex4f &_difuse, const _vertex4f &_specular){
    id = _id;
    directional = _directional;
    position = _position;
    ambiental = _ambiental;
    difuse = _difuse;
    specular = _specular;
}

void Light::enable(){
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(id);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        if(directional) {
            glRotatef(alfa,0,1,0);
            glRotatef(beta,1,0,0);
        }
        glLightfv(id, GL_POSITION, (GLfloat *) &position);
        glLightfv(id, GL_AMBIENT,  (GLfloat *) &ambiental);
        glLightfv(id, GL_SPECULAR, (GLfloat *) &specular);
        glLightfv(id, GL_DIFFUSE,  (GLfloat *) &difuse);
    glPopMatrix();
}

void Light::disable(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glDisable(GL_LIGHTING);
        glDisable(id);
    glPopMatrix();
}

void Light::setID(const GLenum &_id){
    id = _id;
}

void Light::setDirectional(const bool &_directional){
    if(_directional){
        directional = true;
        position[3] = 0;
    }else{
        directional = false;
        position[3] = 1;
    }
}

void Light::setPosition(const _vertex3f &_position){
    position.x = _position.x;
    position.y = _position.y;
    position.z = _position.z;
}

void Light::setDirection(const GLfloat &_alfa, const GLfloat &_beta){
    alfa = _alfa;
    beta = _beta;
}

void Light::setAmbiental(const _vertex4f &_ambiental){
    ambiental = _ambiental;
}

void Light::setDifuse(const _vertex4f &_difuse){
    difuse = _difuse;
}

void Light::setSpecular(const _vertex4f &_specular){
    specular = _specular;
}
