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
#define FOR(i,l) for(int i = 0; i < l ; ++i)

using namespace std;

int main(){
	int fil,col;
	char input;
	int rl,cl,rg,cg,rm,cm;
	while(cin >> fil >> col && fil != NULL){
		int table[fil][col];
		cin >> rl >> cl >> rg >> cg >>rm >> cm;
		FOR(i,fil){
			FOR(j,col){
				cin >> input;
				if(input == '.')
					table[i][j] = 0;
				else 
					table[i][j] = 1;
			}
		}		
	}	
}

void printtable(int table[][]){
	FOR(i,fil){
		FOR(j,col){
			cout << table[i][j];
		}
		cout << endl;	
	}
}