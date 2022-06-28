// https://www.beecrowd.com.br/judge/pt/problems/view/2532

/**

There is a wizard on a game that must defeat the Demogorgon. He does it by taking away
all the monster's P points of life. To accomplish that the wizard has N spells and each
of them can take Di points of life. To use a spell you lose Mi points. Each spell can be
used exactly once. 
Given the points of life of the demogorgon, the spells the wizard has, the damage it does
and the points he loses, compute the minimum amount of points a wizard can use to defeat the
monster.

**/

#include <iostream>
#include <vector>

#define inf 0x3f3f3f3f

using namespace std;

int min_int(int i, int j){
	if(i < j) return i;
	return j;
}

int pd(int n, int p, int m[1001][2001], int dano[1001], int mana[1001]){

	int i, j;
	for(i = 1; i <= n; i++){
		m[i][0] = inf;
	}

	for(j = 0; j <= p; j++){
		m[0][j] = inf;
	}

	for(i = 1; i <= n; i++){
		for(j = 1; j <= p; j++){

			if(dano[i] >= j){
				m[i][j] = min_int(mana[i], m[i - 1][j]);
			}
			else{ 
				m[i][j] = min_int(mana[i] + m[i - 1][j - dano[i]], m[i - 1][j]);
			}
		}
	}

	if(m[n][p] == inf) return -1;
	return m[n][p];

}

int main(){
	int n, p;
	while(cin>>n>>p){

		int obj;
		int m[1001][2001];
		int dano[1001];
		int mana[1001];
		dano[0] = -1;
		mana[0] = -1;

		int d, mn;
		for(obj = 1; obj <= n; obj++){
			cin>>d>>mn;
			dano[obj] = d;
			mana[obj] = mn;
		}

		cout<<pd(n, p, m, dano, mana)<<endl;
	}
	return 0;
}