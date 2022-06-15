//https://www.beecrowd.com.br/judge/pt/problems/view/1470

/**

Develope a program to check if there is a "folding" of the line
that could reach the number given. When you fold a line, you sum 
the elements of the line that meet and invert the order of it.

**/

#include <iostream>
#include <iterator>
#include <vector>
#include <cmath> 

using namespace std;

bool encontrar_dobras(vector<long long> fita_og, vector<long long> fita_dob, int size_og, int size_dob){

	bool found = true;
	if(size_og == size_dob){ 
		int i;
		int j = size_og - 1;
		for(i = 0; i < size_og; i++){
			if(fita_og[i] != fita_dob[i] && fita_og[i] != fita_dob[j]){
				found = false;
				break;
			}
			j--;
		}
		return found;
	}

	else if(size_dob >= ceil(size_og/2)){
		int pos;
		for(pos = size_og - size_dob - 1; pos >= 0; pos--){
			int i = pos;
			int j = pos + 1;

			vector<long long> aux; 
			int count = 0;
			while(true){
				if(i == -1 && j == size_og) break;
				if(i == -1 && j < size_og){
					aux.push_back(fita_og[j]);
					j++;
				}
				else if(i > -1 && j == size_og){
					aux.push_back(fita_og[i]);
					i--;
				}
				else if(i > -1 && j < size_og){
					aux.push_back(fita_og[i] + fita_og[j]);
					j++;
					i--;
				}
				count++;
			}

			if(encontrar_dobras(aux, fita_dob, count, size_dob)){
				return true;
			}
		}

		for(pos = size_dob - 1; pos < size_og - 1; pos++){
			int i = pos;
			int j = pos + 1;

			vector<long long> aux; 
			int count = 0;
			while(true){
				if(i == -1 && j == size_og) break;
				if(i == -1 && j < size_og){
					aux.push_back(fita_og[j]);
					j++;
				}
				else if(i > -1 && j == size_og){
					aux.push_back(fita_og[i]);
					i--;
				}
				else if(i > -1 && j < size_og){
					aux.push_back(fita_og[i] + fita_og[j]);
					j++;
					i--;
				}
				count++;
			}

			if(encontrar_dobras(aux, fita_dob, count, size_dob)){
				return true;
			}
		}

		return false;
	}	
	else{
		int pos;
		for(pos = 0; pos < size_og - 1; pos++){
			int i = pos;
			int j = pos + 1;

			vector<long long> aux; 
			int count = 0;
			while(true){
				if(i == -1 && j == size_og) break;
				if(i == -1 && j < size_og){
					aux.push_back(fita_og[j]);
					j++;
				}
				else if(i > -1 && j == size_og){
					aux.push_back(fita_og[i]);
					i--;
				}
				else if(i > -1 && j < size_og){
					aux.push_back(fita_og[i] + fita_og[j]);
					j++;
					i--;
				}
				count++;
			}

			if(encontrar_dobras(aux, fita_dob, count, size_dob)){
				return true;
			}
		}
		return false;
	}
}

int main(){
	int n_og;
	while(cin>>n_og){
		int i;
		long long n;
		vector<long long> fita_og;
		for(i = 0; i < n_og; i++){
			cin>>n;
			fita_og.push_back(n);
		}
		int n_dob;
		cin>>n_dob;
		vector<long long> fita_dob;
		for(i = 0; i < n_dob; i++){
			cin>>n;
			fita_dob.push_back(n);
		}
		
		if(encontrar_dobras(fita_og, fita_dob, n_og, n_dob)) cout<<"S"<<endl;
		else cout<<"N"<<endl;
	}

	return 0;
}