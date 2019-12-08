#ifndef MODEL_MATERIAL_H
#define MODEL_MATERIAL_H

#include <GL/gl.h>
#include <vertex.h>

class Material{
    public:
        Material();
        Material(_vertex4f _ambiental, _vertex4f _difuse, _vertex4f _specular, float _brillo);
        void setAmbiental(const _vertex4f &_ambiental);
        void setDifuse(const _vertex4f &_difuse);
        void setSpecular(const _vertex4f &_specular);
        void setBrillo(const float &_brillo);
        void enable();
        void operator =(Material &_material);
    private:
        _vertex4f ambiental, difuse, specular;
        float brillo;
};

#endif
