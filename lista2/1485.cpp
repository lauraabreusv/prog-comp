// https://www.beecrowd.com.br/judge/pt/problems/view/1485

/**

Turkish roulette is a luck game in which there is a roulette with S spaces and B balls
(each one of them numbered randomly between +- 64). For each one of the B balls exactly 
one player will bet on it.
After spinning the wheel the B balls are sequentially thrown and each ball stops between
two adjacent numbers. The resultant value of the ball is the multiplication of the number
of the ball by the sum of the two numbers of the positions the balls are on.
If the resultant value of the ball is positive, the player that bet on the ball wins this 
value, and if negative the player pays this value.
The program aims to calculate the biggest value the table can collet given the conditions
of the game.

**/

#include <iostream>

using namespace std;

int max_int(int a, int b){
	if(a > b) return a;
	return b;
}

int pd(int roleta[251], int bolas[126], int i, int j, int max_i, int max_j, int m[251][126]){
	if(i > max_i-1 && j <= max_j) return -999999999;
	else if(j > max_j) return 0;
	else if(m[i][j] != -100000000) return m[i][j];
	return m[i][j] = max_int(pd(roleta, bolas, i+1, j, max_i, max_j, m), pd(roleta, bolas, i+2, j+1, max_i, max_j, m)-((roleta[i]+roleta[i+1])*bolas[j]));
}

void monta(int roleta[251], int bolas[126], int i, int j, int resultados[251], int posicao){

	int m[251][126];
	int k, l;
	for(k = 0; k < i; k++) {
		for(l = 0; l < j; l++) {
			m[k][l] = -100000000;
		}
	}
	m[0][0]= pd(roleta, bolas, 0, 0, i-1, j-1, m);
	resultados[posicao] = m[0][0];
}

int main() {
	int s, b;
	cin>>s>>b;
	while(s && b){
		int roleta[251];
		int i, j, k, l;
		for(i = 0; i < s; i++){
			cin>>roleta[i];
		}
		int bolas[126];
		for(j = 0; j < b; j++){
			cin>>bolas[j];
		}

		int resultados[256];
		for(k = 0; k < s; k++){
			monta(roleta, bolas, s, b, resultados, k);
			int aux = roleta[0];
			for(l = 0; l < s-1; l++){
				roleta[l] = roleta[l+1];
			}
			roleta[s-1] = aux;
		}

		int result, maior = resultados[0];
		for(k = 1; k < s; k++){
			if(resultados[k] > maior) maior = resultados[k];
		}

		cout<<maior<<endl;

		cin>>s>>b;
	}
	return 0;
}