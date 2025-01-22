#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include <queue>
using namespace std;

class Nodo{
   public:
    pair<char,int> nodo;
    vector<Nodo*> vecinos;
    Nodo(char letra, int peso){
        nodo = make_pair(letra,peso);
    }
    
};


void imprimirVect(vector<Nodo*> v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]->nodo.first<<" ";
    }
}

vector<int> dijkstra(vector<vector<int>> &matriz){
    int n = matriz.size();
    vector<int> caminoCorto(n,99999);
    vector<bool> nodos(n,0);
    caminoCorto[0] = 0;
    vector<Nodo*> arbol;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(matriz[i][j] != 0){
                int peso = matriz[i][j];
                nodos[j] = 1;
                if(caminoCorto[i] + peso < caminoCorto[j]){
                    caminoCorto[j] = caminoCorto[i] + peso;
                    Nodo* n = new Nodo(i+65,caminoCorto[i]);
                    nodos.push_back(n);
                }
            }      
        }
    }

    return caminoCorto;
}



void imprimirNodos(queue<int> nodo){
    queue<char> nodos;
    cout<<"Los nodos presentes son: ";
    while(!nodo.empty()){
        nodos.push(nodo.front() + 65);
        
    }
    while(!nodos.empty()){
        cout<<nodos.front()<<" ";
        nodos.pop();
    }
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
    int contador = 0;
    string linea;
    queue<int> nodos;

    for(int i = 0; i < n; i++){
        getline(archivo,linea);
        stringstream ss(linea);
        string parte;
        int j = 0;
        while(getline(ss,parte,',')){
            int peso = stoi(parte);
            matrizAdy[i][j] = peso;
            if(i == j){
                //pa los ciclos
                matrizAdy[i][j] = 0;
            }
            if(matrizAdy[i][j] != 0){
                nodos.push(contador);
                contador++;
            }
            j++;
        }
    }

    imprimirNodos(nodos);
    cout<<endl;
    vector<int> caminoCorto = dijkstra(matrizAdy);
    char nodoFin;
    cout<<"Ponga el nodo a llegar: ";
    cin>>nodoFin; 

    int nodoFinInt = nodoFin - 65;
    for(int i = 0; i < caminoCorto.size(); i++){
        if(nodoFinInt == i){
            cout<<"El valor total del camino más corto: "<<caminoCorto[i]<<endl;
        }
    } 
    

    return 0;
}