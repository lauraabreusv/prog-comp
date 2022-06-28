// https://www.beecrowd.com.br/judge/pt/problems/view/1522

/**

There are three piles of cards numbered from 0-9. The player can throw only
one of the cards on top of the piles and can choose either one, two or all 
of the cards if the sum of the values are multiple of three. The game ends 
when all cards are removed from the piles. The program should detect if the 
game can be won or not, given the piles of cards.

**/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int pd(vector<int> p1, vector<int> p2, vector<int> p3, int i, int j, int k, int m[101][101][101], int n){
	if(m[i][j][k] != -1) return m[i][j][k];
	else{
		if(i != n && p1[i]%3 == 0){
			m[i][j][k] = pd(p1, p2, p3, i+1,j,k,m,n);
			return m[i][j][k];
		}
		if(j != n && p2[j]%3 == 0){
			m[i][j][k] = pd(p1, p2, p3, i,j+1,k,m,n);
			return m[i][j][k];	
		} 
		if(k != n && p3[k]%3 == 0){
			m[i][j][k] = pd(p1, p2, p3, i,j,k+1,m,n);
			return m[i][j][k];
		}

		bool found = false;
		if(i != n && j != n && (p1[i] + p2[j])%3 == 0){
			m[i][j][k] = pd(p1, p2, p3, i+1, j+1, k, m, n);
			if(m[i][j][k]) return m[i][j][k];
		}

		if(i != n && k != n && (p1[i] + p3[k])%3 == 0){
			m[i][j][k] = pd(p1, p2, p3, i+1, j, k+1, m, n);
			if(m[i][j][k]) return m[i][j][k];
		}

		if(j != n && k != n && (p2[j] + p3[k])%3 == 0){
			m[i][j][k] = pd(p1, p2, p3, i, j+1, k+1, m, n);
			if(m[i][j][k]) return m[i][j][k];
		}

		if(i != n && j != n && k != n && (p1[i] + p2[j] + p3[k])%3 == 0){
			m[i][j][k] = pd(p1, p2, p3, i+1, j+1, k+1, m, n);
			if(m[i][j][k]) return m[i][j][k];
		}

		return 0;
	}
}

int main(){
	int n;
	cin>>n;

	while(n){

		vector<int> pilha1, pilha2, pilha3;
		int p1, p2, p3;

		int i, j, k;
		for(i = 0; i < n; i++){
			cin>>p1>>p2>>p3;
			pilha1.push_back(p1);
			pilha2.push_back(p2);
			pilha3.push_back(p3);
		}

		int m[101][101][101];

		for(i = 0; i <= n; i++){
			for(j = 0; j <= n; j++){
				for(k = 0; k <= n; k++){
					m[i][j][k] = -1;
				}
			}
		}

		m[n][n][n] = 1; 

		cout<<pd(pilha1, pilha2, pilha3, 0, 0, 0, m, n)<<endl;

		cin>>n;
	}

	return 0;
}