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

	int N,M;
	while(cin >> N >> M && N != 0 && M != 0){
		int temp,buscar;
		int cont = 0;
		map<int,int>::iterator it;
		map<int,int> first;
		map<int,int> second;
		for(int i = 0 ; i < N ; ++i){
			cin >> temp;
			first[temp]++;
		}
		for(int j = 0 ; j < M ; ++j){
			cin >> temp;
			second[temp]++;
		}
		if(first.SZ > second.SZ){
			for(it = second.begin(); it != second.end() ; ++it){
				if(first[(*it).first] == 1)cont++;
			}
		}else{
			for(it = first.begin(); it != first.end() ; ++it){
				if(second[(*it).first] == 1)cont++;
			}
		}
		cout << cont << endl;
	}

	return 0;
}
