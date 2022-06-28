// / https://www.beecrowd.com.br/judge/pt/problems/view/1645

/*

You should compute the number of increasing subsequences of size K are present
in a sequence of random numbers of size N.

*/

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

long long int pd(vector<int> seq, int n, int k){
	//0
	long long int m[100][101]; 
	int i, j;
	for(j = 2; j <= k; j++){
		for(i = 0; i < n; i++){
			m[i][j] = 0;
		}
	}

	//k = 2
	for(i = 1; i < n; i++){
		int aux;
		for(aux = 0; aux < i; aux++){
			if(seq[aux] < seq[i]) m[i][2]++;
		}
	}

	//rest
	for(j = 3; j <= k; j++){
		for(i = j - 1; i < n; i++){
			if(m[i][j - 1] == 0) m[i][j] = 0;
			else{
				int l;
				for(l = i - 1; l >= j - 2; l--){
					if(seq[l] < seq[i]){
						m[i][j] += m[l][j - 1];
					}
				}
			}
		}
	}

	long long int count = 0;
	for(i = 0; i < n; i++){
		count+=m[i][k];
	}

	return count;

}


int main(){

	int n, k;
	cin>>n>>k;
	while(n != 0){
		int i;
		vector<int> seq;
		int a;
		for(i = 0; i < n; i++){
			cin>>a;
			seq.push_back(a);
		}

		if(k == 1) cout<<n<<endl;
		else cout<<pd(seq, n, k)<<endl;
		cin>>n>>k;
	}

	return 0;
}