#ifndef _MODEL_PIECES_H
#define _MODEL_PIECES_H

#include <model_basic.h>
#include <constant_hierarchical.h>
#include <model_revolution.h>
#include <model_ply.h>
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

class TanqueCannon: public Triangulos3D{
    public:
        TanqueCannon();
        void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

    protected:
        Revolution tubo_abierto;
};

class WattBola: public Triangulos3D{
    public:
        WattBola();
        WattBola(float angle);
        void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
        void setAngle(float angle);

    private:
        float angZ;

    protected:
        Esfera esfera;
        ModelPly objPly;
};

class WattLanza: public Triangulos3D{
    public:
        WattLanza();
        WattLanza(float angle);
        void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
        void setAngle(float ang);
    
    private:
        float angZ;
        
    protected:
        Cilindro cilindro;
};

class WattTransversal: public Triangulos3D{
    public:
        WattTransversal();
        WattTransversal(float angle);
        void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
        void setAngle(float ang);

    private:
        float angZ;

    protected:
        Cilindro cilindro;
};

class WattBrazo: public Triangulos3D{
    public:
        WattBrazo();
        WattBrazo(float angle);
        void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
        void setAngle(float ang);
    
    private:
        float angZ;

    protected:
        WattBola bola;
        WattLanza lanza;
        WattTransversal transversal;
};

class WattCaja: public Triangulos3D{
    public:
        WattCaja();
        WattCaja(float angle);
        void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
        void setAngle(float ang);

    private:
        float angZ;

    protected:
        Cilindro cilindro;
};

class WattCuerpo: public Triangulos3D{
    public:
        WattCuerpo();
        WattCuerpo(float angle);
        void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
        void setAngle(float ang);

    private:
        float angZ;

    protected:
        WattBrazo brazo;
        WattCaja caja;
};

class WattColumna: public Triangulos3D{
    public:
        WattColumna();
        WattColumna(float angle);
        void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
        void setAngle(float ang);

    private:
        float angZ;

    protected:
        Cilindro cilindro;
};

class WattBase: public Triangulos3D{
    public:
        WattBase();
        WattBase(float angle);
        void draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
        void setAngle(float ang);

    private:
        float angZ;

    protected:
        Cubo cubo;
};

#endif