#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>
using namespace std;

class Nodo{
   public:
    pair<char,int> nodo;
    vector<Nodo*> sig;
    Nodo(char letra, int peso) : nodo(letra,peso){}
    
};


void imprimirVect(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
}

int dijkstra(vector<vector<int>> &matriz){
    int numCorto = 0;
    int n = matriz.size();
    vector<int> caminoCorto(n,99999);
    vector<bool> nodos(n,0);
    caminoCorto[0] = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(matriz[i][j] != 0){
                int peso = matriz[i][j];
                if(caminoCorto[i] + peso < caminoCorto[j]){
                    caminoCorto[j] = caminoCorto[i] + peso;
                }
            }
            
        }
    }

    imprimirVect(caminoCorto);
    return numCorto;
}



void imprimirMatriz(vector<vector<int>> &matriz, int filas, int col){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < col;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
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

    vector<vector<int>> matrizAdy(n,vector<int>(n));

    string linea;
    for(int i = 0; i < n; i++){
        getline(archivo,linea);
        stringstream ss(linea);
        string parte;
        int j = 0;
        while(getline(ss,parte,',')){
            int peso = stoi(parte);
            matrizAdy[i][j] = peso;
            if(i == j){
                matrizAdy[i][j] = 0;
            }
            j++;
        }
    }

    int a = dijkstra(matrizAdy);
    
    return 0;
}