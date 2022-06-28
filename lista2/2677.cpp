// https://www.beecrowd.com.br/judge/pt/problems/view/2677

/**

There is a game for two players in which there is a sequence of N odd and N even numbers 
(being the number N always odd). This sequence is ordered randomly and at each round of 
the game a player choses head or tail number. The player that choses the biggest amount 
of even numbers wins. The program should compute with how many even numbers the first player
wins, considering that both players are playing with optimal strategies. 


**/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int max_int(int i, int j){
	if(i > j) return i;
	return j;
}

int min_int(int i, int j){
	if(i < j) return i;
	return j;
}

void pd(int n, vector<int> seq){
	int m[1000][1000];
	int i, d;

	for(i = 0; i < n - 1; i++){
		if(seq[i]%2 == 0 || seq[i + 1]%2 == 0) m[i][i+1] = 1;
		else m[i][i + 1] = 0;
		int d = 1;

	}
	
	for(d = 2; d < n; d++){
		for(i = 0; i < n - d; i++){
			if(d%2 == 1){	
				if(seq[i]%2 == 0 || seq[i + d]%2 == 0){
					m[i][i + d] = min_int(m[i + 1][i + d], m[i][i + d - 1]) + 1;
				}
				else m[i][i + d] = max_int(m[i + 1][i + d], m[i][i + d - 1]);
			}
			else{
				m[i][i + d] = min_int(m[i + 1][i + d], m[i][i + d - 1]);
			}
		}
	}

	cout<<m[0][n - 1]<<endl;
}

int main(){

	int n;
	cin>>n;
	while(n){

		int i, num;
		vector<int> seq;
		for(i = 0; i < 2*n; i++){
			cin>>num;
			seq.push_back(num);
		}

		pd(2*n, seq);

		cin>>n;
	}

	return 0;
}