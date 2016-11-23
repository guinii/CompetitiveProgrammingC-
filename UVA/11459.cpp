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

int main(){
	vector<pair<int,int> > snakes;
	vector<pair<int,int> >dies;
	int N;
	cin >> N;
	for(int jugadas = 0 ; jugadas < N ; ++jugadas){
		int p,s,d; //# of players, snakes or ladders,dies
		cin >> p >> s >> d;
		int v[p];
		for (int i =0 ; i < p ; ++i)v[i]=1;
		snakes.clear();
		dies.clear();
		vector<int> table(vector<int>(100,-1)); 
		for(int sn = 0 ; sn < s ; sn++){ //snakes or ladders
			int sninput1 , sninput2;
			cin >> sninput1 >> sninput2;
			table[sninput1] = 2; //guardamos la primera part
			table[sninput2] = 3; //segunda parte para el salto
			snakes.PB(MP(sninput1,sninput2)); //first mouth or bottom, second tail or top
		}
		for(int nd = 0 ; nd < d ; ++nd){ //each rolled die.
			int ndinput;
			cin >> ndinput;
			dies.PB(MP(nd%p ,ndinput));
		}
		//inicialamos juegos
		for(int i = 0 ; i < d ; ++i){
			v[i%p] += dies[i].second;
			if(table[v[i%p]] == 2 ) {
				for(vector<pair<int,int> >::const_iterator it = snakes.begin() ; it != snakes.end() ; ++it){
					if(it->first == v[i%p]){
						v[i%p] = it->second;
						break;
					}
				}
			}
			if(v[i%p] >= 100){
				v[i%p]=100;
				break;
			}
		}
		for(int i = 0 ; i < p ; ++i){
			cout << "Position of player "<< i+1 << " is " << v[i] << "."<<endl; 
		}
	}
}


