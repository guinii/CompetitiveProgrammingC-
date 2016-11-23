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
	int N,rondas = 1;
	while(cin >> N && N != -1){
		int atemps = 0;
		int aciertos = 0;
		string final = ""; 
		string sol,guess;
		cin >> sol;
		cin >> guess;
		int numleters = sol.length(); 
		string visitados="";
		//catch caracters and find to the string and count the misses, if it's not found return -1 , do it while it's not -1 because can be repeted
		//delete that caracter for making easy to find later the caracters.
		for(int i = 0 ; i < guess.length(); ++i){
			int a = visitados.find_first_of(guess[i]);
			if( a == -1){
				if(atemps>=7){
					break;
				}
				if(aciertos >= numleters){
					break;
				}
				int pos = sol.find_first_of(guess[i]);
				if(pos == -1 ){
					atemps++;
				}else{
					aciertos++;
					pos = sol.find_first_of(guess[i],pos+1);
					while(pos != -1){
						aciertos++;
						pos = sol.find_first_of(guess[i],pos+1);
					}
				}
			visitados+=guess[i];
			}
		} 
		if(atemps>=7 && aciertos<numleters){
				final+="You lose.";
		}else if(aciertos >= numleters){
			final+="You win.";
		}else{
			final+="You chickened out.";
		}
		cout << "Round " << rondas << endl;
		cout << final << endl;
		rondas++;
	}
	
}