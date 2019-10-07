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
