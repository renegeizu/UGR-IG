#ifndef _MODEL_PIECES_H
#define _MODEL_PIECES_H

#include <model_basic.h>
#include <model_revolution.h>
#include <triangulos3D.h>

using namespace std;

class TanqueChasis: public Triangulos3D{
    public:
        TanqueChasis();
        void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
        float altura;

    protected:
        Revolution rodamiento;
        Cubo base;
};

class TanqueTorreta: public Triangulos3D{
    public:
        TanqueTorreta();
        void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
        float altura;
        float anchura;

    protected:
        Cubo base;
        Piramide parte_trasera;
};

class Cannon: public Triangulos3D{
    public:
        Cannon();
        void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

    protected:
        Revolution tubo_abierto;
};

#endif