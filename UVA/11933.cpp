#include <iostream>
#include <vector> // vectores
#include <list>   // listas
#include <map>    // diccionarios
#include <algorithm>
#include <utility> //make_pair
#include <cmath>
#include <set>
#include <bitset>
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
	while( cin >> N && N!=0){
		int dec1 = 0 , dec2 = 0;
		bool flag = false;
		while(N&(-N)){
			if(flag){
				dec1 |= N&(-N);	
			}else{
				dec2 |= N&(-N);
			}
			flag = !flag;
			N -= N&(-N);
		}
		cout << dec2 << " " << dec1 << endl;
	}


	return 0;
}