#ifndef MODEL_LIGHT_H
#define MODEL_LIGHT_H

#include <GL/gl.h>
#include <vertex.h>

class Light{
    public:
        Light();
        Light(const GLenum &_id, const bool &_directional, const _vertex3f &_position, const _vertex4f &_ambiental, const _vertex4f &_difuse, const _vertex4f &_specular);
        void enable();
        void disable();
        void setID(const GLenum &_id);
        void setDirectional(const bool &_directional);
        void setPosition(const _vertex3f &_position);
        void setDirection(const GLfloat &_alfa, const GLfloat &_beta);
        void setAmbiental(const _vertex4f &_ambiental);
        void setDifuse(const _vertex4f &_difuse);
        void setSpecular(const _vertex4f &_specular);
    private:
        GLfloat alfa, beta;
        GLenum id;
        _vertex4f position, ambiental, specular, difuse;
        bool directional;
};

#endif