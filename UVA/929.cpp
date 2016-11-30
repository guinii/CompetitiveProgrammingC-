#include <iostream>
#include <vector> // vectores
#include <list>   // listas
#include <map>    // diccionarios
#include <algorithm>
#include <utility> //make_pair
#include <cmath>
#include <set>
#include <sstream>
#include <string>


#define X first
#define Y second
#define LI long long
#define MP make_pair
#define PB push_back
#define SZ size()
#define SQ(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace std;
// Complexity: ElogV - Input: undirected graph

typedef int V;          // tipo de costes
typedef pair<V,int> P;  // par de (coste,nodo)
typedef set<P> S;       // conjunto de pares

int N;                  // numero de nodos
vector<P> A[10001];     // listas adyacencia (coste,nodo)

// int prec[201]; // predecesores (nodes from s to t)
// another way to obtain a path (above all, if there is
// more than one, consists in using BFS from the target
// and add to the queue those nodes that lead to the 
// minimum cost in the preceeding node)

V dijkstra(int s, int t) {
    S m;                          // cola de prioridad
    vector<V> z(N, 1000000000);   // distancias iniciales
    z[s] = 0;                     // distancia a s es 0
    m.insert(MP(0, s));           // insertar (0,s) en m
    while (m.SZ > 0) {
        P p = *m.begin();   // p=(coste,nodo) con menor coste
        m.erase(m.begin()); // elimina este par de m
        if (p.Y == t) return p.X; // cuando nodo es t, acaba
        // para cada nodo adjacente al nodo p.Y
        for (int i = 0; i < (int)A[p.Y].SZ; i++) {
            // q = (coste hasta nodo adjacente, nodo adjacente)
            P q(p.X + A[p.Y][i].X, A[p.Y][i].Y);
            // si q.X es la menor distancia hasta q.Y
            if (q.X < z[q.Y]) {
                m.erase(MP(z[q.Y], q.Y)); // borrar anterior
                m.insert(q);              // insertar q
                z[q.Y] = q.X;             // actualizar distancia
				// prec[q.Y] = p.Y;       // actualizar predecesores
            }
        }
    }
    return -1;
}



int main(){
	int W;
	cin >> W;
	while(W--){
		int lin,col;
		cin >> lin;
		cin >> col;
		int temp[lin][col];
		N = lin*col;
		for(int i = 0 ; i < lin ; ++i){
			for(int j = 0 ; j < col ; ++j){
				cin >> temp[i][j];
			}
		}
		for(int i = 0 ; i < lin*col ; ++i){
			A[i].clear();
		}
		for(int i =0  ; i < lin ; ++i){
			for(int j = 0 ; j < col ;++j){
				if(i != lin-1){
					if(j != col-1){
						A[j+(i*col)].PB(MP(temp[i][j+1],(j+(i*col))+1));
					}
					A[j+(i*col)].PB(MP(temp[i+1][j],(j+((i+1)*col))));
				}else{
					if(j != col-1){
						A[j+(i*col)].PB(MP(temp[i][j+1],(j+(i*col))+1));
					}
				}
			}
		}
		if(lin == 1 && col == 1){
			cout << temp[0][0] << endl;
		}else{
			cout << dijkstra(0,(lin*col)-1) << endl;
		}
		/*for(int i = 0 ; i < (lin*col)  ; ++i){
			for(vector<P>::iterator  it = A[i].begin() ; it != A[i].end() ; ++it){
				cout << "nodo " << i <<  " a " << it->second << " con coste " << it->first << endl;
			} 
		}*/
	}	
}