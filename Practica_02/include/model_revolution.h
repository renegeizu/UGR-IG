#ifndef MODEL_REVOLUTION_H
#define MODEL_REVOLUTION_H

#include <triangulos3D.h>

using namespace std;

class Revolution: public Triangulos3D{
    public:
        Revolution();
        void parametros(vector<_vertex3f> perfil1, int num1);
        vector<_vertex3f> perfil; 
        int num;
};

class Cono: public Revolution{
    public:
        Cono(int num = 6);
};

class Cilindro: public Revolution{
    public:
        Cilindro(int num = 6);
};

class Esfera: public Revolution{
    public:
        Esfera(int num = 6, int numPerfil = 10, int radio = 1.0);
};

class Peon: public Revolution{
    public:
        Peon(int num = 6);
};

#endif
