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
	string firstline;
	int N,B,H,W; //N=participants, B = dinero , H =#hotels , W = #weeks
	while(cin >> N && N != NULL){
		int pricefinal = 999999999;
		cin >> B >> H >> W;
		//cout << H << endl;
		for(int i = 0 ; i < H ; ++i){
			int pricehotel;
			cin >> pricehotel; //price x person x week
			//cout << "precio x hoel" << pricehotel;
			for(int j = 0 ; j < W ; ++j){
				int nb; //number beds of each week
				cin >> nb;
				if( nb >= N && N*pricehotel <=B ){
					//cout << "entro con "<< N*pricehotel;
					if(pricefinal > N*pricehotel)pricefinal=N*pricehotel;
				}
			} 
		}
		if(pricefinal == 999999999){
			cout << "stay home" << endl;
		}else{
			cout << pricefinal << endl;
		}
	}
	
}