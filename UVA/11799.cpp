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
	int N,n,def,p;
	cin >> N;
	for(int i = 0 ; i < N ; ++i){
		def = 0;
		cin >> n;
		for(int j = 0 ; j < n ; ++j){
			cin >> p;
			if(p>def)def=p;
		}
		cout << "Case " << i+1 <<": " <<def <<endl;
	}
}



