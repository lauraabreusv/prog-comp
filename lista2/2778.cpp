// https://www.beecrowd.com.br/judge/pt/problems/view/2778

/**

there is a matrix NxM and the player wants to move from 1,1 to position N,M. 
Each cell has a cost and the total cost of the path is the sum of all the cells
the player crossed. The task is to compute the minimum cost of the path. However, 
there are aditional rules:
1. If you are at cell i,j you can go only to cells i+1,j or i,j+1 or i,j-1.
2. No cell can be visited more than once
3. It is not allowed to cross more than X cells of value 0
4. It is not allowed to cross more than Y cells of negative value
It is possible that there is no answer, and if so print impossible.

**/

#include <iostream>

#define inf 0x3f3f3f3f

int c[100][100]; 
int m[100][100][21][21][3]; 

//uso inf - 1 para o caso do max

//0: esq
//1: dir
//2: cima

using namespace std;

int min_int(int a, int b){
	if(a < b) return a;
	return b;
}

int pd(int dir, int i, int j, int qtd_zeros, int qtd_neg, int max_dir){
	if(m[i][j][qtd_zeros][qtd_neg][dir] != inf){
		return m[i][j][qtd_zeros][qtd_neg][dir];
	}


	if((c[i][j] == 0 && qtd_zeros == 0) || (c[i][j] < 0 && qtd_neg == 0)){
		return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;
	}

	if(i == 0 && j == 0){
		return m[i][j][qtd_zeros][qtd_neg][dir] = c[i][j];
	}

	if(dir == 0 || j == 0){ 

		if((j == max_dir - 1 || dir == 1) && i == 0) {
			return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;
		}
		if(j == max_dir - 1 || dir == 1){ 
			if(c[i][j] == 0) return m[i][j][qtd_zeros][qtd_neg][dir] = pd(2, i - 1, j, qtd_zeros - 1, qtd_neg, max_dir);

			if(c[i][j] < 0){
				int u = pd(2, i - 1, j, qtd_zeros, qtd_neg - 1, max_dir);
				if(u == inf - 1) return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;
				return m[i][j][qtd_zeros][qtd_neg][dir] = u + c[i][j];
			} 

			int u  = pd(2, i - 1, j, qtd_zeros, qtd_neg, max_dir);
			if(u == inf - 1) return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;
			return m[i][j][qtd_zeros][qtd_neg][dir] = u + c[i][j];
		}

		if(i == 0){ 

			if(c[i][j] == 0) return m[i][j][qtd_zeros][qtd_neg][dir] = pd(0, i, j + 1, qtd_zeros - 1, qtd_neg, max_dir) + c[i][j];

			if(c[i][j] < 0){
				int d = pd(0, i, j + 1, qtd_zeros, qtd_neg - 1, max_dir);
				if(d == inf - 1) return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;
				return m[i][j][qtd_zeros][qtd_neg][dir] = d + c[i][j];
			}

			int d = pd(0, i, j + 1, qtd_zeros, qtd_neg, max_dir);
			if(d == inf - 1) return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;
			return m[i][j][qtd_zeros][qtd_neg][dir] = d + c[i][j];
		}

		int d, u;

		if(c[i][j] == 0){
			d = pd(0, i, j + 1, qtd_zeros - 1, qtd_neg, max_dir);
			u = pd(2, i - 1, j, qtd_zeros - 1, qtd_neg, max_dir);
		}
		else if(c[i][j] < 0){
			d = pd(0, i, j + 1, qtd_zeros, qtd_neg - 1, max_dir);
			u = pd(2, i - 1, j, qtd_zeros, qtd_neg - 1, max_dir);
		}
		else{
			d = pd(0, i, j + 1, qtd_zeros, qtd_neg, max_dir);
			u = pd(2, i - 1, j, qtd_zeros, qtd_neg, max_dir);
		}

		if(d == inf - 1 && u == inf - 1) return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;

		return m[i][j][qtd_zeros][qtd_neg][dir] = min_int(d, u) + c[i][j];

	}

	if(dir == 1 || j == max_dir - 1){ 

		if((j == 0 || dir == 0) && i == 0) return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;

		if(j == 0 || dir == 0){ 

			if(c[i][j] == 0) return m[i][j][qtd_zeros][qtd_neg][dir] = pd(2, i - 1, j, qtd_zeros - 1, qtd_neg, max_dir) + c[i][j];

			if(c[i][j] < 0){
				int u = pd(2, i - 1, j, qtd_zeros, qtd_neg - 1, max_dir);
				if(u == inf - 1) return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;
				return m[i][j][qtd_zeros][qtd_neg][dir] = u + c[i][j];
			} 

			int u = pd(2, i - 1, j, qtd_zeros, qtd_neg, max_dir);
			if(u == inf - 1) return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;
			return m[i][j][qtd_zeros][qtd_neg][dir] = u + c[i][j];
		}

		if(i == 0){ 

			if(c[i][j] == 0) return m[i][j][qtd_zeros][qtd_neg][dir] = pd(1, i, j - 1, qtd_zeros - 1, qtd_neg, max_dir) + c[i][j];

			if(c[i][j] < 0){
				int e = pd(1, i, j - 1, qtd_zeros, qtd_neg - 1, max_dir);
				if(e == inf - 1) return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;
				return m[i][j][qtd_zeros][qtd_neg][dir] = e + c[i][j];
			}

			int e = pd(1, i, j - 1, qtd_zeros, qtd_neg, max_dir);
			if(e == inf - 1) return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;
			return m[i][j][qtd_zeros][qtd_neg][dir] = e + c[i][j];
		}
		int e, u;

		if(c[i][j] == 0){
			e = pd(1, i, j - 1, qtd_zeros - 1, qtd_neg, max_dir);
			u = pd(2, i - 1, j, qtd_zeros - 1, qtd_neg, max_dir);
		}
		else if(c[i][j] < 0){
			e = pd(1, i, j - 1, qtd_zeros , qtd_neg - 1, max_dir);
			u = pd(2, i - 1, j, qtd_zeros, qtd_neg - 1, max_dir);
		}
		else{
			e = pd(1, i, j - 1, qtd_zeros, qtd_neg, max_dir);
			u = pd(2, i - 1, j, qtd_zeros, qtd_neg, max_dir);
		}

		if(e == inf - 1 && u == inf - 1) return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;

		return m[i][j][qtd_zeros][qtd_neg][dir] = min_int(e, u) + c[i][j];

	}

	if(i == 0){
		int e, d;

		if(c[i][j] == 0){
			e = pd(1, i, j - 1, qtd_zeros - 1, qtd_neg, max_dir);
			d = pd(0, i, j + 1, qtd_zeros - 1, qtd_neg, max_dir);
		}
		else if(c[i][j] < 0){
			e = pd(1, i, j - 1, qtd_zeros, qtd_neg - 1, max_dir);
			d = pd(0, i, j + 1, qtd_zeros, qtd_neg - 1, max_dir);
		}
		else{
			e = pd(1, i, j - 1, qtd_zeros, qtd_neg, max_dir);
			d = pd(0, i, j + 1, qtd_zeros, qtd_neg, max_dir);
		}

		if(e == inf - 1 && d == inf - 1) return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;

		return m[i][j][qtd_zeros][qtd_neg][dir] = min_int(e, d) + c[i][j];
	}
	int e, d, u;
	if(c[i][j] == 0){
		e = pd(1, i, j - 1, qtd_zeros - 1, qtd_neg, max_dir);
		d = pd(0, i, j + 1, qtd_zeros - 1, qtd_neg, max_dir);
		u = pd(2, i - 1, j, qtd_zeros - 1, qtd_neg, max_dir);
	}
	else if(c[i][j] < 0){
		e = pd(1, i, j - 1, qtd_zeros , qtd_neg - 1, max_dir);
		d = pd(0, i, j + 1, qtd_zeros, qtd_neg - 1, max_dir);
		u = pd(2, i - 1, j, qtd_zeros, qtd_neg - 1, max_dir);
	}
	else{
		e = pd(1, i, j - 1, qtd_zeros, qtd_neg, max_dir);
		d = pd(0, i, j + 1, qtd_zeros, qtd_neg, max_dir);
		u = pd(2, i - 1, j, qtd_zeros, qtd_neg, max_dir);
	}

	if(e == inf - 1 && u == inf - 1 && d == inf - 1) return m[i][j][qtd_zeros][qtd_neg][dir] = inf - 1;

	return m[i][j][qtd_zeros][qtd_neg][dir] = min_int(min_int(e, u), d) + c[i][j];

}

int main(){
	int n, m2, x, y;
	while(cin>>n>>m2>>x>>y){
		int i, j, k, l, o;
		int aux;
		for(i = 0; i < n; i++){
			for(j = 0; j < m2; j++){
				cin>>aux;
				c[i][j] = aux;
			}
		}
		for(i = 0; i < n; i++){
			for(j = 0; j < m2; j++){
				for(k = 0; k <= x; k++){
					for(l = 0; l <= y; l++){
						for(o = 0; o < 3; o++){
							m[i][j][k][l][o] = inf;
						}
					}
				}
			}
		}

		int resp = pd(2, n - 1, m2 - 1, x, y, m2);
		if(resp == inf - 1) cout<<"Impossivel"<<endl;
		else cout<<resp<<endl;

	}

	return 0;
}