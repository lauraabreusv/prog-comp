// https://www.beecrowd.com.br/judge/pt/problems/view/2884

/**

There are N switchers that control M lamps, in which each switcher controls a 
subset of lamps. Given a subset of L lamps that are turned on, someone has to turn
all of them off and tries to do that by changing the state of the switchers in the
ordem of 1, 2, 3, ..., N, 1, 2.. until all of them are turned of. The program is to
compute the number of attempts of the person to swtich everything off and, in case that
it is not possible, return -1.

**/

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class interruptor{
public:
	int index;
	vector<int> lampadas_por_int;
};

int main(){
	int n_int, n_lam;
	cin>>n_int>>n_lam;

	vector<int> lampadas;
	int i;
	for(i = 0; i <= n_lam; i++){ 
		lampadas.push_back(0);
	}

	int n_acesas;
	cin>>n_acesas;
	for(i = 0; i < n_acesas; i++){
		int l;
		cin>>l;
		lampadas[l] = 1;
	}

	vector<int> lampadas_init = lampadas;

	vector<interruptor> interruptores; 
	for(i = 0; i < n_int; i++){
		interruptor inter;
		inter.index = i + 1;
		int k;
		cin>>k;
		int j;
		int l;
		for(j = 0; j < k; j++){
			cin>>l;
			inter.lampadas_por_int.push_back(l);

		} 
		interruptores.push_back(inter); 
	}

	int count = 0;
	while(true){
		for(i = 0; i < n_int; i++){
			vector<int>::iterator it;
			for(it = interruptores[i].lampadas_por_int.begin(); it != interruptores[i].lampadas_por_int.end(); it++){
				if(lampadas[*it]) lampadas[*it] = 0;
				else lampadas[*it] = 1;
			}

			count++;
			int j;
			for(j = 1; j <= n_lam; j++){ 
				if(lampadas[j])					
					break;
			}

			if(j == n_lam + 1) break; 
		}

		if(i < n_int){ 
			cout<<count<<endl;
			break;
		}
		else if(lampadas == lampadas_init){
			cout<<"-1"<<endl;
			break;
		}
	}

	return 0;

}