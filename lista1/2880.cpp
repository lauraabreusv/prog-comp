// https://www.beecrowd.com.br/judge/pt/problems/view/2880

/**

Given a cryptography machine that replaces a letter with another (it is never replaces
by itself), discover in how many possible places a word can be given a "crib", that is,
an encrypted message.

**/

#include <iostream>
#include <string>

using namespace std;

int main(){

	string cifra, palavra;
	cin>>cifra;
	cin>>palavra;

	int count = 0;
	int tam_cifra = cifra.length();
	int tam_palavra = palavra.length();
	bool found = false;

	int i, j, k;
	for(i = 0; i < tam_cifra - tam_palavra + 1; i++){
		k = i;
		for(j = 0; j < tam_palavra; j++){
			if(palavra[j] == cifra[k]){
				found = true;
				break;
			}
			k++;
		}
		if(!found) count++;
		else found = false;
	}

	cout<<count<<endl;

	return 0;
}