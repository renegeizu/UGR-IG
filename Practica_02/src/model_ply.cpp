#include <model_ply.h>

ModelPly::ModelPly(){

}

int ModelPly::parametros(char* archivo){
    int n_ver, n_car;
    vector<float> ver_ply;
    vector<int> car_ply;
    _file_ply::read(archivo, ver_ply, car_ply);
    n_ver = ver_ply.size()/3;
    n_car = car_ply.size()/3;
    printf("Number of vertices = %d\nNumber of faces = %d\n", n_ver, n_car);
    vertices.resize(n_ver);
    caras.resize(n_car);
    for(int i = 0; i < n_ver; i++){
        vertices[i].x = ver_ply[i*3];
        vertices[i].y = ver_ply[i*3 + 1];
        vertices[i].z = ver_ply[i*3 + 2];
    }
    for(int i = 0; i < n_car; i++){
        caras[i]._0 = car_ply[i*3];
        caras[i]._1 = car_ply[i*3 + 1];
        caras[i]._2 = car_ply[i*3 + 2];
    }
    return(0);
}