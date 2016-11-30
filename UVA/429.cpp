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


int N = 1000;                  // numero de nodos
vector<int> A[10001];   // listas de adyacencia

bool calculate(string s1, string s2){
	if(s1.size() == s2.size()){
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


int main(){
	int Q;
	cin >> Q;
	for(int y = 0 ; y < Q ; ++y){ 
		map<string,int> mymap;
		string inp; 
		for(int i = 0 ; i < 10001 ; ++i){
			A[i].clear();
		} 
		vector<pair<string,int> > temp;
		temp.clear();
		mymap.clear();
		int cont = 1;
		while(cin >> inp && inp != "*"){
			mymap[inp] = cont;
			pair<string,int> p =  MP(inp,cont);
			temp.PB(p);
			cont++;
		}
		for(vector<pair<string,int> >::iterator it = temp.begin() ; it != temp.end() ; ++it){
			for(vector<pair<string,int> >::iterator it2 = temp.begin() ; it2 != temp.end() ; ++it2){
				if(calculate(it->first,it2->first)){
					A[it->second].PB(it2->second);
				} 
			}
		}
		//apaño molt feo per agafar la part del final!
		cin.ignore();
		string line;
		getline(cin,line);
		while(line.size() != 0){
			int p = line.find(" ");
			string in = line.substr(0,p);
			string out = line.substr(p+1);
			int final = BFS(mymap[in],mymap[out]);
			if(final == -1 )final = 0;
			cout << in << " " << out << " " << final <<endl;
			getline(cin,line);
		}
		if(y!=Q-1)cout <<endl;
	}
	
}