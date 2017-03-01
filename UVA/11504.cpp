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

int N = 100000;                  // numero de nodos
vector<int> A[1000001];   // listas de adyacencia


int BFS(int s, int t) { // distancia entre s y t
  if (s == t) return 0;
  int l[100001], k = 0;  // inicializar cola
  vector<int> v(N, -1); // inicializar distancias
  l[k++] = s;           // agregar s a la cola
  v[s] = 0;             // distancia hasta s es 0
  for (int i = 0; i < k; i++){
    // para todos los nodos adyacentes de l[i]
		for (int j = 0; j < (int)A[l[i]].SZ; j++){
	      // si el vecino no se ha visitado
	      if (v[A[l[i]][j]] < 0) {
		        // actualizar su distancia
		    v[A[l[i]][j]] = v[l[i]] + 1;
		        // si encontramos t, devolver resultado
		    if (A[l[i]][j] == t) return v[t];
		        // agregar a la cola
		    l[k++] = A[l[i]][j];
	      }
	  	}
	}
  return -1;
}


int main(){
	int Q;
	cin >> Q;
	while(Q--){
		int n,m;
		cin >> n >> m; //n numero de fitxas y m numero de lineas
		for(int i = 0 ; i < m ; ++i){

		}

	}
}