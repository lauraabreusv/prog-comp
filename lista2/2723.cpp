// https://www.beecrowd.com.br/judge/pt/problems/view/2723

/**

Santa Claus has N gifts to deliver and can divide them into two piles (A or B). So there 
is balance, both piles can have the maximum difference of weight of 5kg. You should compute
if there is a way to place the gifts in the order they are given so the two piles are never
unbalanced. 

**/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void pd(vector<int> p, int n){
	int m[10000][6];

	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < 6; j++){
			m[i][j] = 0;
		}
	}

	if(p[0] > 5){
		cout<<"Ho Ho Ho!"<<endl;
		return;
	}

	m[0][p[0]] = 1;

	for(i = 1; i < n; i++){
		bool found = false;
		for(j = 0; j < 6; j++){
			if(m[i - 1][j]){ 
				int esq = j + p[i];
				int dir = abs(j - p[i]);

				if(esq <= 5){
					found = true;
					m[i][esq] = 1;
				}
				if(dir <= 5){
					found = true;
					m[i][dir] = 1;
				}
			}
		}
		if(!found){
			cout<<"Ho Ho Ho!"<<endl;
			return;
		}
	}
	cout<<"Feliz Natal!"<<endl;
}

int main(){

	int t;
	cin>>t;

	int caso;
	for(caso = 0; caso < t; caso++){
		int n;
		cin>>n;

		int i;
		vector<int> pesos;
		int p;
		for(i = 0; i < n; i++){
			cin>>p;
			pesos.push_back(p);
		}

		pd(pesos, n);
	}

	return 0;
}