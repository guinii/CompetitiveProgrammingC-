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

bool calculate(string s1, string s2){
	if(s1.size() != s2.size()){
		return false;
	}else{
		int cont = 0;
		for(int i = 0 ; i < s1.size() ; ++i){
			if(s1[i] != s2[i]){
				cont++;
			}
		}
		if(cont == 1){
			return true;
		}else{
			return false;
		}
	}
}

int N;                  // numero de nodos
vector<int> A[10001];   // listas de adyacencia

int BFS(int s, int t) { // distancia entre s y t
  if (s == t) return 0;
  int l[10001], k = 0;  // inicializar cola
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

/*int main() {
  N = 6;      // solucion 0-1-3-5, distancia 3
  A[0].PB(1); // arista (0, 1)
  A[0].PB(2); // arista (0, 2)
  A[1].PB(2); // arista (1, 2)
  A[1].PB(3); // arista (1, 3)
  A[2].PB(4); // arista (2, 4)
  A[3].PB(5); // arista (3, 5)
  A[4].PB(3); // arista (4, 3)
  cout << BFS(0, 5) << endl;
}*/


  int main(){
	int Q;
	map<string,int> mymap;
	while(cin >> Q && Q != NULL ){
		string inp; 
		vector<pair<string,int> > temp;
		int cont = 1;
		while(cin >> inp && inp != "*"){
			mymap[inp] = cont;
			pair<string,int> p =  MP(inp,cont);
			temp.PB(p);
			cont++;
		}
		for(vector<pair<string,int> >::iterator it = temp.begin() ; it != temp.end() ; ++it){
			for(vector<pair<string,int> >::iterator it2 = it ; it2 != temp.end() ; ++it2){
				if(calculate(it->first,it2->first)){
					//cout << "una dif entre " << it->first << " y " << it2->first << endl;
					A[it->second].PB(it2->second);
				} 
			}
		}
		string in,out;
		cin >> in >> out;
		int res ;
		cout << mymap[in] << "  "  << mymap[out] <<endl;
		res = BFS(mymap[in],mymap[out]);
		cout << " a" << res << endl;
	}
	
}