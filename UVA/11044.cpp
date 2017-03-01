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
	int N ;
	cin >> N;
	while(N){
		int fil,col;
		int contfil = 0;
		int contcol = 0;
		cin >> fil >> col;
		fil -= 2;
		col -= 2;
		if(fil%3 !=0)contfil++;
		if(col%3 != 0)contcol++;
		while(fil >= 3){
			if(fil%3 == 0)contfil++;
			fil--;
		}
		while(col >= 3){
			if(col%3 == 0)contcol++;
			col--;
		}
		cout << contcol*contfil << endl;
		N--;
	}

}


