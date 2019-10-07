#include <model_revolution.h>

Revolution::Revolution(){

}

void Revolution::parametros(vector<_vertex3f> perfil, int num){
    int i, j;
    _vertex3f vertice_aux;
    _vertex3i cara_aux;
    int num_aux;
    num_aux = perfil.size();
    vertices.resize(num_aux*num);
    for(j = 0; j < num; j++){
        for(i = 0; i < num_aux; i++){
            vertice_aux.x = perfil[i].x * cos(2.0*M_PI*j/(1.0*num)) + perfil[i].z * sin(2.0*M_PI*j/(1.0*num));
            vertice_aux.z = -perfil[i].x * sin(2.0*M_PI*j/(1.0*num)) + perfil[i].z * cos(2.0*M_PI*j/(1.0*num));
            vertice_aux.y = perfil[i].y;
            vertices[i + j * num_aux] = vertice_aux;
        }
    }
    if(fabs(perfil[0].x) > 0.0){

    }
    if (fabs(perfil[num_aux-1].x) > 0.0){

    }
}

Cono::Cono(int num){
    vector<_vertex3f> perfil(3);
    perfil[0].x = 0;        perfil[0].y = 0.5;      perfil[0].z = 0;
    perfil[1].x = 0.5;      perfil[1].y = -0.5;     perfil[1].z = 0;
    perfil[2].x = 0;        perfil[2].y = -0.5;     perfil[2].z = 0;
    parametros(perfil, num);
}

Cilindro::Cilindro(int num){
    vector<_vertex3f> perfil(4);
    perfil[0].x = 0;        perfil[0].y = 0.5;      perfil[0].z = 0;
    perfil[1].x = 0.5;      perfil[1].y = 0.5;      perfil[1].z = 0;
    perfil[2].x = 0.5;      perfil[2].y = -0.5;     perfil[2].z = 0;
    perfil[3].x = 0;        perfil[3].y = -0.5;     perfil[3].z = 0;
    parametros(perfil, 6);
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
    parametros(perfil, 6);
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
    parametros(perfil, 6);
}