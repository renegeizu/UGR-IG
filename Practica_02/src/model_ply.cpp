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
    return(0);
}