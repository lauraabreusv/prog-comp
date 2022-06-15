// https://www.beecrowd.com.br/judge/pt/problems/view/1767

/**

You should pack the biggest amount of toys you can without exceeding the 
total weight of 50kg.

**/

#include <iostream>
#include <vector>

using namespace std;

class Pacote{
public:
	int peso;
	int n_brinquedos;
};

void maximo(vector<Pacote> pacotes, int i, int j, int m[301][51], int c[301][51], int u[301][51]){

	if(m[i - 1][j] > (m[i - 1][j - pacotes[i].peso] + pacotes[i].n_brinquedos)){ //nao usa
		m[i][j] = m[i - 1][j];
		c[i][j] = c[i - 1][j];
		u[i][j] = u[i - 1][j];
	}
	else{
		m[i][j] = m[i - 1][j - pacotes[i].peso] + pacotes[i].n_brinquedos;
		c[i][j] = c[i - 1][j - pacotes[i].peso] + pacotes[i].peso;
		u[i][j] = u[i - 1][j - pacotes[i].peso] + 1;
	}
}

void maior_valor(vector<Pacote> pacotes, int qtd, int custo){

	int i, j;
	int m[301][51];
	int c[301][51];
	int u[301][51];

	for(i = 0; i <= qtd; i++){
		for(j = 0; j <= custo; j++){
			m[i][j] = 0;
			c[i][j] = 0;
			u[i][j] = 0;
		}
	}

	for(i = 1; i <= qtd; i++){
		for(j = 1; j <= custo; j++){
			if(pacotes[i].peso > j){
				m[i][j] = m[i - 1][j];
				c[i][j] = c[i - 1][j];
				u[i][j] = u[i - 1][j];
			}
			else{
				maximo(pacotes, i, j, m, c, u);
			}
		}
	}

	// for(i = 0; i <= qtd; i++){
	// 	for(j = 0; j <= custo; j++){
	// 		cout<<m[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	cout<<m[qtd][custo]<<" brinquedos"<<endl;
	cout<<"Peso: "<<c[qtd][custo]<<" kg"<<endl;
	cout<<"sobra(m) "<<qtd - u[qtd][custo]<<" pacote(s)"<<endl;
	cout<<endl;
}

int main(){
	int n;
	cin>>n; //numero de viagens

	int i;
	for(i = 0; i < n; i++){
		int qtd;
		cin>>qtd;

		vector<Pacote> pacotes;
		Pacote cabeca;
		cabeca.peso = 0;
		cabeca.n_brinquedos = 0;
		pacotes.push_back(cabeca);
		int j;
		for(j = 0; j < qtd; j++){ //numero de pacotes
			int b, p;
			cin>>b>>p;
			Pacote pct;
			pct.peso = p;
			pct.n_brinquedos = b;
			pacotes.push_back(pct);
		}

		maior_valor(pacotes, qtd, 50);
	}

	return 0;
}