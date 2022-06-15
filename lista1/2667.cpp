// https://www.beecrowd.com.br/judge/pt/problems/view/2667

/**

There is a game in which, to win, the player has to be the one to say the number N.
The rules are: you start by one or two and the next ones have to be either n + 1 or n + 2.
The goal is to know for given N if the first player should start with one or two to win,
considering that both of the players would play the best options always.

**/

#include <iostream>
#include <string>

using namespace std;

int main(){

	string n;
	cin>>n;

	int size = n.length();
	int i;
	int sum = 0;
	for(i = 0; i < size; i++){
		sum+=n[i];
	}

	if(sum%3 == 0){
		cout<<'0'<<endl;
	}
	else if((sum - 1)%3 == 0){
		cout<<'1'<<endl;
	}
	else cout<<'2'<<endl;

	return 0;
}

