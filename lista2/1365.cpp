// https://www.beecrowd.com.br/judge/pt/problems/view/1365

/**

You should find the smallest area of a rectangle that a group of K friends
can sit in a movies, given R lines with C chair in which one of them and 
the already occupied sits. Consider that they always buy the sits in order. 

**/

#include <iostream>

#define inf 0x3f3f3f3f

using namespace std;

int main(){
	int r, c, grupo;
	cin>>r>>c>>grupo;

	while(r){

		int i, j, k, l;
		char assentos[301][301];
		int base[301][301]; 

		for(j = 0; j < c; j++){
			base[0][j] = 0;
		}

		for(i = 1; i <= r; i++){
			for(j = 0; j < c; j++){
				cin>>assentos[i][j];
				int aux = base[i - 1][j];
				if(assentos[i][j] == 'X') base[i][j] = aux;
				else base[i][j] = aux + 1;
			}
		}

		if(grupo == 1) cout<<"1"<<endl;
		else{
			int min = r*c;

			for(i = 1; i <= r; i++){
				if(min == grupo) break;
				for(k = i; k <= r; k++){
					if((k - i + 1)*c >= grupo){
						int j, l, aux;
						for(j = 0; j < c; j++){
							int var_cumu = 0;
							for(l = j; l < c; l++){
								var_cumu += base[k][l] - base[i - 1][l];

								if(var_cumu >= grupo){
									if((k  - i + 1)*(l - j + 1) < min) min = (k - i + 1)*(l - j + 1);
									break; 
								}
							}
							if(l == c) break;
						}
						if(min == grupo) break;
					}
				}
			}
			cout<<min<<endl;
		}
		cin>>r>>c>>grupo;
	}

	return 0;
}