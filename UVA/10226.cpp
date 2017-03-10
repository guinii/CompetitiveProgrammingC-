#include <iostream>
#include <vector> // vectores
#include <list>   // listas
#include <map>    // diccionarios
#include <algorithm>
#include <utility> //make_pair
#include <cmath>
#include <set>
#include <sstream>
#include <iomanip>
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
	map<string,float> trees;
	while(N--){
		string name;
		trees.clear();
		float cont = 0;
		while( getline(cin,name)){
			if(name.length() == 0)break;
			cont++;
			trees[name]++;
		}
		if(trees.size() != 0){
			for(map<string,float>::iterator it = trees.begin() ; it!= trees.end() ; ++it){
				float result = ((*it).second/cont)*100; //((*it).second/cont)*100;
				cout << (*it).first << " " << setprecision(4)<<fixed <<result << endl;
			}
			if(N!=0)cout << endl;
		}else{
			N++;
		}
	}
	return 0;
}