#include <model_revolution.h>

Revolution::Revolution(){

}

void Revolution::make_revolution(vector<_vertex3f> perfil, int num, float lAng, float gAng){
    revolutionY(perfil, num, lAng, gAng);
}

void Revolution::revolutionY(vector<_vertex3f> perfil, int num, float lAng, float gAng){
    if(gAng != lAng && gAng >= 0 && lAng >= 0 && gAng <= 360 && lAng <= 360){
        float angSup = (gAng >= lAng) ?  gAng : lAng,
              angInf = (lAng <= gAng) ?  lAng : gAng,
              angInc = (angSup-angInf)/(num-1);
        int tPerfil = perfil.size();
        bool tapaSup = (perfil[0].x == 0 && perfil[0].z == 0), tapaInf = (perfil[tPerfil-1].x == 0 && perfil[tPerfil-1].z == 0),
             spin = (angSup-angInf == 360);
        int vIndex = tapaSup, tIndex = 0, cPerfil = tPerfil - tapaSup - tapaInf;
        bool tapasF = (tapaInf && tapaSup && (cPerfil < 3));
        int vSize = tapaSup+tapaInf+(num*cPerfil),
            tSize = (tapaSup+tapaInf)*(num-(!spin)) + (cPerfil-1)*(num-(!spin))*2 + 2*cPerfil*tapasF;
        vertices.resize(vSize);
        caras.resize(tSize);
        float angulo = angInf;
        for(int i = 0; i < num; i++){
            for(int j = tapaSup; j < tPerfil-tapaInf; j++){
                vertices[vIndex++] = rotarY(perfil[j], gradosRadianes(angulo));
            }
            angulo += angInc;
        }
        if(tapaSup) vertices[0] = perfil[0];
        if(tapaInf) vertices[vIndex++] = perfil[tPerfil-1];
        int tCuerpo = ((vIndex-tapaInf-tapaSup)/cPerfil)-1;
        for(int i = 0; i < cPerfil-1; i++){
            int vUp = i+tapaSup, vLeft = vUp+1, vRight = vLeft+cPerfil;
            for(int j = 0; j < tCuerpo+spin; j++){
                caras[tIndex++] = _vertex3i(vUp, vLeft, vRight);
                caras[tIndex++] = _vertex3i(vRight, vRight-1, vUp);
                vUp += cPerfil;
                vLeft = vRight;
                vRight = ((j+2) != (tCuerpo+1)) ?  vLeft+cPerfil : vRight = i+1+tapaSup;
            }
        }
        if(tapaSup){
            int vUp = 0, vLeft = 1, vRight = vLeft+cPerfil;
            for(int i = 0; i < tCuerpo+spin; i++){
                caras[tIndex++] = _vertex3i(vUp, vLeft, vRight);
                vLeft = vRight;
                vRight = ((i+2) != (tCuerpo+1)) ? vRight+cPerfil : vRight = 1;
            }
        }
        if(tapaInf){
            int vUp = vertices.size()-1, vLeft = vUp-1, vRight = vLeft-cPerfil;
            for(int i = 0; i < tCuerpo+spin; i++){
                caras[tIndex++] = _vertex3i(vUp, vLeft, vRight);
                vLeft = vRight;
                vRight = ((i+2) != (tCuerpo+1)) ? vRight-cPerfil : vRight = vIndex-2;
            }
        }
        if(tapasF && !spin){
            int vUpIzq = 0, vDownIzq = vertices.size()-1, vExIzq = vDownIzq-1;
            int vUpDer = 0, vDownDer = vertices.size()-1, vExDer = vUpDer+1;
            for(int i = 0; i < cPerfil; i++){
                caras[tIndex++] = _vertex3i(vDownIzq--, vUpIzq, vExIzq--);
                caras[tIndex++] = _vertex3i(vUpDer++, vDownDer, vExDer++);
            }
        }
    }
}

float Revolution::gradosRadianes(float grados){
    return grados*M_PI/180.0;
}

_vertex3f Revolution::rotarY(_vertex3f vertice, float angulo){
    _vertex3f vRotado;
    vRotado.x = cos(angulo)*vertice.x + sin(angulo)*vertice.z;
    vRotado.y = vertice.y;
    vRotado.z = -sin(angulo)*vertice.x + cos(angulo)*vertice.z;
    return vRotado;
}

Cono::Cono(int num){
    vector<_vertex3f> perfil(3);
    perfil[0].x = 0;        perfil[0].y = 0.5;      perfil[0].z = 0;
    perfil[1].x = 0.5;      perfil[1].y = -0.5;     perfil[1].z = 0;
    perfil[2].x = 0;        perfil[2].y = -0.5;     perfil[2].z = 0;
    make_revolution(perfil, num);
}

Cilindro::Cilindro(int num){
    vector<_vertex3f> perfil(4);
    perfil[0].x = 0;        perfil[0].y = 0.5;      perfil[0].z = 0;
    perfil[1].x = 0.5;      perfil[1].y = 0.5;      perfil[1].z = 0;
    perfil[2].x = 0.5;      perfil[2].y = -0.5;     perfil[2].z = 0;
    perfil[3].x = 0;        perfil[3].y = -0.5;     perfil[3].z = 0;
    make_revolution(perfil, num);
}

Esfera::Esfera(int num, int numPerfil, int radio){
    float angIni = M_PI/2, angCal = M_PI/(numPerfil-1);
    vector<_vertex3f> perfil(numPerfil);
    for(int i = 0; i < numPerfil; ++i){
        perfil[i].x = radio * cos(angIni);
        perfil[i].y = radio * sin(angIni);
        perfil[i].z = 0;
        angIni -= angCal;
    }
    make_revolution(perfil, num);
}

Peon::Peon(int num){
    vector<_vertex3f> perfil(13);
    perfil[0].x = 0;        perfil[0].y = 1.4;      perfil[0].z = 0;
    perfil[1].x = 0.3;      perfil[1].y = 1.4;      perfil[1].z = 0;
    perfil[2].x = 0.5;      perfil[2].y = 1.2;      perfil[2].z = 0;
    perfil[3].x = 0.55;     perfil[3].y = 1;        perfil[3].z = 0;
    perfil[4].x = 0.5;      perfil[4].y = 0.8;      perfil[4].z = 0;
    perfil[5].x = 0.3;      perfil[5].y = 0.6;      perfil[5].z = 0;
    perfil[6].x = 0.5;      perfil[6].y = 0.6;      perfil[6].z = 0;
    perfil[7].x = 0.4;      perfil[7].y = 0.5;      perfil[7].z = 0;
    perfil[8].x = 0.4;      perfil[8].y = -0.4;     perfil[8].z = 0;
    perfil[9].x = 0.5;      perfil[9].y = -0.7;     perfil[9].z = 0;
    perfil[10].x = 1;       perfil[10].y = -1.1;    perfil[10].z = 0;
    perfil[11].x = 1;       perfil[11].y = -1.4;    perfil[11].z = 0;
    perfil[12].x = 0;       perfil[12].y = -1.4;    perfil[12].z = 0;
    make_revolution(perfil, num);
}

Tubo::Tubo(int num){
    vector<_vertex3f> perfil(2);
    perfil[0].x = 0.5;      perfil[0].y = 2.0;      perfil[0].z = 0;
    perfil[1].x = 0.5;      perfil[1].y = 0.0;      perfil[1].z = 0;
    make_revolution(perfil, num);
}