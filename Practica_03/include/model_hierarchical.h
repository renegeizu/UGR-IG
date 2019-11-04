#ifndef _MODEL_HIERARCHICAL_H
#define _MODEL_HIERARCHICAL_H

#include <model_pieces.h>
#include <triangulos3D.h>

using namespace std;

class Tanque: public Triangulos3D{
    public:
        Tanque();
        void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
        float giro_tubo;
        float giro_torreta;
        float giro_tubo_min;
        float giro_tubo_max;

    protected:
        TanqueChasis chasis;
        TanqueTorreta torreta;
        Cannon tubo;
};

class Watt: public Triangulos3D{
    public:
        Watt();
        void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
};

#endif