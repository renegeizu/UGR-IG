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

#endif
