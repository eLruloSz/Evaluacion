#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void imprimirMatriz(int matriz[6][6]){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6;j++){
            cout<<matriz[i][j]<<endl;
        }
    }
}


int main(){
    ifstream archivo("matrizEjemplo.txt");
    if(!archivo){
        cout<<"No existe el archivo"<<endl;
        return 1;
    }
    string primeraLinea;
    getline(archivo,primeraLinea);
    int n = stoi(primeraLinea);

    int matrizAdy[n][n];
    string linea;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            getline(archivo,linea);
            stringstream ss(linea);
            string parte;
            getline(ss,parte,',');
                int peso = stoi(parte);
                matrizAdy[i][j] = peso;
                
        }
    }
    imprimirMatriz(matrizAdy);
    
    return 0;
}