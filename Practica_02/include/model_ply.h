#ifndef MODEL_PLY_H
#define MODEL_PLY_H

#include <file_ply_stl.hpp>
#include <triangulos3D.h>

using namespace std;

class ModelPly: public Triangulos3D{
    public:
        ModelPly();
        int parametros(char* archivo);
};

#endif
