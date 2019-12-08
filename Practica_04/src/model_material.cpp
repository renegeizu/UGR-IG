#include <model_material.h>

Material::Material(){

}

Material::Material(_vertex4f _ambiental, _vertex4f _difuse, _vertex4f _specular, float _brillo){
    ambiental = _ambiental;
    difuse = _difuse;
    specular = _specular;
    brillo = _brillo;
}

void Material::setAmbiental(const _vertex4f &_ambiental){
    ambiental = _ambiental;
}

void Material::setDifuse(const _vertex4f &_difuse){
    difuse = _difuse;
}

void Material::setSpecular(const _vertex4f &_specular){
    specular = _specular;
}

void Material::setBrillo(const float &_brillo){
    brillo = _brillo;
}

void Material::enable(){
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   (GLfloat *) &ambiental);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   (GLfloat *) &difuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  (GLfloat *) &specular);
    glMaterialf(GL_FRONT_AND_BACK,  GL_SHININESS, brillo);
}

void Material::operator =(Material &_material){
    setAmbiental(_material.ambiental);
    setBrillo(_material.brillo);
    setDifuse(_material.difuse);
    setSpecular(_material.specular);
}
