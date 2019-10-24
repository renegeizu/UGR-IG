#ifndef MODEL_REVOLUTION_H
#define MODEL_REVOLUTION_H

#include <triangulos3D.h>

using namespace std;

class Revolution: public Triangulos3D{
    public:
        Revolution();
        void make_revolution(vector<_vertex3f> perfil, int num, float lAng = 0, float gAng = 360);
        void revolutionY(vector<_vertex3f> perfil, int num, float lAng, float gAng);
        float gradosRadianes(float grados);
        _vertex3f rotarY(_vertex3f vertice, float angulo);
        vector<_vertex3f> perfil;
};

class Cono: public Revolution{
    public:
        Cono(int num = 12);
};

class Cilindro: public Revolution{
    public:
        Cilindro(int num = 12);
};

class Esfera: public Revolution{
    public:
        Esfera(int num = 12, int numPerfil = 10, int radio = 1.0);
};

class Peon: public Revolution{
    public:
        Peon(int num = 12);
};

class Tubo: public Revolution{
    public:
        Tubo(int num = 12);
};

#endif
