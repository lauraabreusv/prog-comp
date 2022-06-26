//https://www.beecrowd.com.br/judge/pt/problems/view/1288

/**

You should find out if it is possible to destroy a castle with resistence
R with N projectiles with the sum of them having the maximum weight of K. 

**/

#include <iostream>
#include <vector>

using namespace std;

int max_int(int i, int j){
	if(i > j) return i;
	return j;
}

int pd(int n, int c, vector<int> p, vector<int> v){
	int m[51][101];

	int i, j;
	for(i = 0; i <= n; i++){
		m[i][0] = 0; 
	}
	for(j = 0; j <= c; j++){
		m[0][j] = 0;
	}

	for(i = 1; i <= n; i++){
		for(j = 1; j <= c; j++){
			if(p[i] > j){
				m[i][j] = m[i - 1][j];
			}
			else{
				m[i][j] = max_int(m[i - 1][j], m[i - 1][j - p[i]] + v[i]);
			}
		}
	}
	return m[n][c];
}

int main(){

	int n_casos;
	cin>>n_casos;

	int caso;
	for(caso = 0; caso < n_casos; caso++){
		int n;
		cin>>n;

		vector<int> poder;
		int pod;
		poder.push_back(-1);
		vector<int> pesos;
		int peso;
		pesos.push_back(-1);
		int i;
		for(i = 0; i < n; i++){
			cin>>pod>>peso;
			poder.push_back(pod);
			pesos.push_back(peso);
		}
		int k, r;
		cin>>k; //capacidade total do canhao
		cin>>r; //resistencia do castelo

		if(pd(n, k, pesos, poder) >= r) cout<<"Missao completada com sucesso"<<endl;
		else cout<<"Falha na missao"<<endl;
	}
	return 0;		
}