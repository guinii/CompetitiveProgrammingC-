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
	int N;
	cin >> N;
	while(N){
		int total = 0;
		int money,tobuy;
		cin >> money >> tobuy;
		for(int i = 0 ; i < tobuy ; ++i){
			int k;
			cin >> k;
			int min = 99999;
			for(int j = 0 ; j < k ; ++j){
				int temp;
				cin >> temp;
				min = MIN(min,temp);
			}
			total+=min;
		}
		if(total > money){
			cout << "no solution" << endl;
		}else{
			cout << total << endl;
		}
		N--;
	}

}


