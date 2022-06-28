// https://www.beecrowd.com.br/judge/pt/problems/view/2713

/**

In an RPG game there are N rooms and each one of them has a moster with X life points.
To each monster, if there is power, the player can increase his damage value in Di units,
and the cost to increase the damage is always 1 to his power. The amount of time it takes
to kill a monster is X/Damage. To win the game, the player has to achieve the final room
and kill all the monsters. You should compute the minimum amount of time the player spents
to kill all the monsters of the match given numbers above.

**/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double min_float(double a, double b){
	if (a < b) return a;
	return b;
}

double pd(vector<int> x, vector<int> d, int n, int k, int v){
	double m[1000][101];

	double count = 0;
	int i, j;
	for(i = 0; i < n; i++){ 
		count+=(double)x[i]/v;
		m[i][0] = count;
	}

	for(i = 0; i < n; i++){
		for(j = 1; j <= k; j++){
			m[i][j] = min_float(((double)x[i]/v) + m[i - 1][j], (double)x[i]/(v + d[i]) + m[i - 1][j - 1]);
		}
	}

	return m[n - 1][k];
}

int main(){
	int n, k, v;
	while(cin>>n>>k>>v){

		vector<int> vidas, danos;
		int x, d;
		int i;
		for(i = 0; i < n; i++){
			cin>>x>>d;
			vidas.push_back(x);
			danos.push_back(d);
		}

		cout<<fixed;
		cout<<setprecision(4)<<pd(vidas, danos, n, k, v)<<endl;
	}

	return 0;
}