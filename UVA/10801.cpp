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
	int n,k;
	while(cin >> n >> k && n != NULL){
		vector<int> times_el;
		for(int i = 0 ; i < n ; ++i){
			int tmp;
			cin >> tmp;
			times_el.PB(tmp);
		}
		vector<vector<int>> elevat(n,vector<int>(n));
		cin.ignore();
		for(int i = 0 ; i < n ; ++i){
			string s;
			getline(cin,s);
			istringstream is(s);
			int p;
			while( is >> p){
				elevat[i].PB(p);
			}
			/*stringstream stream(s);
			while(1){
				int p;
				stream >> p;
				if(!stream)break;
				elevat[i].PB(p);
			}
			//cout << endl;*/
		}
		for(int i = 0 ; i < n ; ++i){
			for(vector<int>::iterator  it = elevat[i].begin() ; it != elevat[i].end() ; ++it){
				cout << *it << " "; 
			}
			cout << endl;
		}
	}
}