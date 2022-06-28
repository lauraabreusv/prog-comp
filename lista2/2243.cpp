// https://www.beecrowd.com.br/judge/pt/problems/view/2243

/**

Given a sequence of cubes placed in N columns, you should compute the height (number of
cubes on the highest column) of the bigger isosceles triangle there is inside the columns.

**/

#include <iostream> 
#include <vector>

using namespace std;

long int min_int(long int i, long int j){
	if(i < j) return i;
	return j;
}

long int pd(vector<long int> h_max, vector<long int> h, long int n){
	long int i;
	for(i = 1; i < n - 1; i++){
		h_max[i] = min(h_max[i - 1] + 1, h[i]);
	}

	long int max = 1;
	for(i = n - 2; i >= 1; i--){
		h_max[i] = min(h_max[i], h_max[i + 1] + 1);
		if(h_max[i] > max) max = h_max[i];
	}

	return max;
}

int main(){

	long int n;
	cin>>n;
	long int tam;
	vector<long int> colunas;
	vector<long int> alturas;
	long int i;
	for(i = 0; i < n; i++){
		cin>>tam;
		colunas.push_back(tam);
		alturas.push_back(1); 
	}

	cout<<pd(alturas, colunas, n)<<endl;

	return 0;
}