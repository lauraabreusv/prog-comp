// https://www.beecrowd.com.br/judge/pt/problems/view/1086

/**

Distribue K wooden boards of dimensions L and variable length of Xi to cover perfectly, 
without overlaping boards or missing spaces, a floor of size NxM.

**/

#include <iostream>
#include <algorithm>

using namespace std;

class Tabua{
public:
	int comprimento;
	bool usada;
	bool usada2;
};

bool sort_function(Tabua i, Tabua j){
	return (i.comprimento>j.comprimento);
}

void total_min(int *tabuas, int n_tabuas){ 
	if(tabuas[0] == n_tabuas+1 && tabuas[1] == n_tabuas+1){
		cout<<"impossivel"<<endl;
	}
	else if(tabuas[0] < tabuas[1]) cout<<tabuas[0]<<endl;
	else cout<<tabuas[1]<<endl;
}

int findMinTabuas(int largura_tabua, int largura, int comprimento, int n_tabuas, Tabua* comprimentos){ 

	int count_dim = 0;
	int count_tabuas = 0;
	int i, j;

	int count_aux = 0;
	while(comprimentos[count_aux].comprimento > comprimento){
		count_aux++;
		if(count_aux == n_tabuas) return n_tabuas+1;
	} 

	while(comprimentos[count_aux].comprimento == comprimento){
		count_dim+=largura_tabua;
		count_tabuas++;
		if(count_dim == largura) return count_tabuas;
		count_aux++;
		if(count_aux == n_tabuas) return n_tabuas+1;
	}

	int backup_j = n_tabuas-1;
	for(i = count_aux; i < n_tabuas; i++){
		if(comprimentos[i].comprimento < comprimento/2) return n_tabuas+1;
		if(comprimentos[i].usada == false){
			for(j = backup_j; j > i; j--){
				if(comprimentos[j].comprimento > comprimento - comprimentos[i].comprimento) {
					backup_j = j; 
					break;
				}
				if(comprimentos[j].comprimento == comprimento - comprimentos[i].comprimento && comprimentos[j].usada == false){
					count_dim+=largura_tabua;
					count_tabuas+=2;
					comprimentos[j].usada = true;
					if(count_dim == largura) return count_tabuas;
					backup_j = j-1; 
					break;
				}
			}
		}
	}
	return n_tabuas+1;
}


int findMinTabuas2(int largura_tabua, int largura, int comprimento, int n_tabuas, Tabua* comprimentos){ 
	int count_dim = 0;
	int count_tabuas = 0;
	int i, j;

	int count_aux = 0;
	while(comprimentos[count_aux].comprimento > comprimento){
		count_aux++;
		if(count_aux == n_tabuas) return n_tabuas+1;
	} 
	while(comprimentos[count_aux].comprimento == comprimento){
		count_dim+=largura_tabua;
		count_tabuas++;
		if(count_dim == largura) return count_tabuas;
		count_aux++;
		if(count_aux == n_tabuas) return n_tabuas+1;
	}
	int backup_j = n_tabuas-1;
	for(i = count_aux; i < n_tabuas; i++){
		if(comprimentos[i].comprimento < comprimento/2) 
			return n_tabuas+1;
		if(comprimentos[i].usada2 == false){
			for(j = backup_j; j > i; j--){
				if(comprimentos[j].comprimento > comprimento - comprimentos[i].comprimento) {
					backup_j = j;
					break;
				}
				if(comprimentos[j].comprimento == comprimento - comprimentos[i].comprimento && comprimentos[j].usada2  == false){
					count_dim+=largura_tabua;
					count_tabuas+=2;
					comprimentos[j].usada2 = true;
					if(count_dim == largura) return count_tabuas;
					backup_j = j-1;
					break;
				}
			}
		}
	}

	return n_tabuas+1;
}


int main(){ 
	int dim1, dim2;
	cin>>dim1>>dim2;
	while(dim1 != 0){ 
		dim1*=100;
		dim2*=100;
		int largura;
		cin>>largura;
		int n_tabuas;
		cin>>n_tabuas;
		int i;
		Tabua comprimentos[100000];
		int tabuas[2] = {n_tabuas+1, n_tabuas+1}; 
		for(i = 0; i < n_tabuas; i++){
			int comp_aux;
			cin>>comp_aux;
			comprimentos[i].comprimento = 100*comp_aux;
			comprimentos[i].usada = false;
			comprimentos[i].usada2 = false;
		} 

		if(dim1%largura == 0 || dim2%largura == 0){
			sort(comprimentos, comprimentos + n_tabuas, sort_function); 
			if(dim1%largura == 0){
				tabuas[0] = findMinTabuas(largura, dim1, dim2, n_tabuas, comprimentos);
			}
			if(dim2%largura == 0){
				tabuas[1] = findMinTabuas2(largura, dim2, dim1, n_tabuas, comprimentos);
			}
			total_min(tabuas, n_tabuas);
		}
		else cout<<"impossivel"<<endl;

		cin>>dim1>>dim2;
	}
	return 0;
}