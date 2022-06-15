// https://www.beecrowd.com.br/judge/pt/problems/view/2683

/**

Find the minium and maximum cost of building the tunnels between the galeries, 
considering that all galeries can be reached from all galeries.

**/

#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

class Arestas{
public:
	int peso;
	int v1;
	int v2;	
};

bool order_arestas(Arestas i, Arestas j){
	return (i.peso<j.peso);
}

int main(){
	long int n_arestas;
	cin>>n_arestas;
	vector<Arestas> arestas;

	int max_entrada = -1;
	int e1, e2, p;
	long int i;
	for(i = 0 ; i < n_arestas; i++){
		cin>>e1>>e2>>p;
		if(e1 > max_entrada){
			max_entrada = e1;
		}
		if(e2 > max_entrada){
			max_entrada = e2;
		}
		Arestas a;
		a.v1 = e1;
		a.v2 = e2;
		a.peso = p;
		arestas.push_back(a);
	}

	map<int, int> entradas;
	for(i = 1; i <= max_entrada; i++){
		entradas[i] = 0;
	}
	map<int, int> entradas_max = entradas;

	sort(arestas.begin(), arestas.end(), order_arestas); 

	long long count_peso = 0;
	long int count_forest = 0;
	for(i = 0; i < n_arestas; i++){
		if(!entradas[arestas[i].v1] && !entradas[arestas[i].v2]){
			count_peso+=arestas[i].peso;
			count_forest++;
			entradas[arestas[i].v1] = count_forest;
			entradas[arestas[i].v2] = count_forest;
		}
		else if(!entradas[arestas[i].v1] && entradas[arestas[i].v2]){
			entradas[arestas[i].v1] = entradas[arestas[i].v2];
			count_peso+=arestas[i].peso;
		}
		else if(entradas[arestas[i].v1] && !entradas[arestas[i].v2]){
			entradas[arestas[i].v2] = entradas[arestas[i].v1];
			count_peso+=arestas[i].peso;
		}
		else if(entradas[arestas[i].v1] != entradas[arestas[i].v2]){
			count_peso+=arestas[i].peso;
			if(entradas[arestas[i].v1] <= entradas[arestas[i].v2]){
				int j;
				int aux = entradas[arestas[i].v2];
				for(j = 1; j <= max_entrada; j++){
					if(entradas[j] == aux){
						entradas[j] = entradas[arestas[i].v1];
					}
				}
			}
			else{
				int j;
				int aux = entradas[arestas[i].v1];
				for(j = 1; j <= max_entrada; j++){
					if(entradas[j] == aux){
						entradas[j] = entradas[arestas[i].v2];
					}
				}
			}
		}
	}

	long long count_peso_max = 0;
	count_forest = 0;

	for(i = n_arestas - 1; i >= 0; i--){
		if(!entradas_max[arestas[i].v1] && !entradas_max[arestas[i].v2]){
			count_peso_max+=arestas[i].peso;
			count_forest++;
			entradas_max[arestas[i].v1] = count_forest;
			entradas_max[arestas[i].v2] = count_forest;
		}
		else if(!entradas_max[arestas[i].v1] && entradas_max[arestas[i].v2]){
			entradas_max[arestas[i].v1] = entradas_max[arestas[i].v2];
			count_peso_max+=arestas[i].peso;
		}
		else if(entradas_max[arestas[i].v1] && !entradas_max[arestas[i].v2]){
			entradas_max[arestas[i].v2] = entradas_max[arestas[i].v1];
			count_peso_max+=arestas[i].peso;
		}
		else if(entradas_max[arestas[i].v1] != entradas_max[arestas[i].v2]){
			count_peso_max+=arestas[i].peso;
			if(entradas_max[arestas[i].v1] <= entradas_max[arestas[i].v2]){
				int j;
				int aux = entradas_max[arestas[i].v2];
				for(j = 1; j <= max_entrada; j++){
					if(entradas_max[j] == aux){
						entradas_max[j] = entradas_max[arestas[i].v1];
					}
				}
			}
			else{
				int j;
				int aux = entradas_max[arestas[i].v1];
				for(j = 1; j <= max_entrada; j++){
					if(entradas_max[j] == aux){
						entradas_max[j] = entradas_max[arestas[i].v2];
					}
				}
			}
		}
	}

	cout<<count_peso_max<<endl;
	cout<<count_peso<<endl;

	return 0;
}