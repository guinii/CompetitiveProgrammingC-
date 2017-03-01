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
	map<char,int> t;
	t['a'] = 1;
	t['d'] = 1;
	t['g'] = 1;
	t['j'] = 1;
	t['m'] = 1;
	t['p'] = 1;
	t['t'] = 1;
	t['w'] = 1;
	t[' '] = 1;
	t['b'] = 2;
	t['e'] = 2;
	t['h'] = 2;
	t['k'] = 2;
	t['n'] = 2;
	t['q'] = 2;
	t['u'] = 2;
	t['x'] = 2;
	t['c'] = 3;
	t['f'] = 3;
	t['i'] = 3;
	t['l'] = 3;
	t['o'] = 3;
	t['r'] = 3;
	t['v'] = 3;
	t['y'] = 3;
	t['s'] = 4;
	t['z'] = 4;
	int N;
	cin >> N;
	string s;
	int cont ;
	int it = 1;
	getline(cin,s);
	while(it < N+1){
		cont = 0 ;
		getline(cin,s);
		for(int i = 0 ; i < s.length() ; ++i){
			cont += t[s[i]];
		}
		cout << "Case #" << it << ": "<<cont <<  endl;
		it++;
	}
}