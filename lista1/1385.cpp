// https://www.beecrowd.com.br/judge/pt/problems/view/1385

/**

Given a line with P numbers, you should split them correctly according
to the rules:
- at the end of the line there is the total sum of products the employee sold
- the sum of each product sold by all the employees must be the number
found at the total line (TP) in the correct position
- no employee sold more than 1000 of each product

**/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){

	int cases;
	cin>>cases;

	int i;
	char p;
	for(i = 0; i < cases; i++){
		vector<string> products;
		cin>>p;
		string aux;
		int count_products = 0;
		while(p != 'T'){
			if(p != 'P'){
				count_products++;
				aux = string() + "P" + p;
				products.push_back(aux);
			}
			cin>>p;
		}
		aux = "Totals";
		products.push_back(aux);
		cin>>aux;
		int j;
		for(j = 0; j < count_products; j++){
			cout<<products[j]<<" ";
		}
		cout<<products[count_products]<<endl;

		aux = "";
		string aux2 = "";
		string aux3;

		vector<int> totals_products = {0, 0, 0, 0, 0, 0};
		
		int count_seller = 0;
		vector<vector<int>> possibilities[5]; //4 sellers  
		vector<string> names; 
		vector<string> numbers;

		while(1){
			cin>>p;
			aux = "";
			aux2 = "";
			aux3 = "";
			while(p > 58){
				aux.push_back(p);
				cin>>p;
			}
			aux2.push_back(p);
			cin>>aux3;
			aux2 = string() + aux2 + aux3;
			names.push_back(aux);
			numbers.push_back(aux2);
			// cout<<"aux: "<<aux<<endl;
			int size_numbers = aux2.length();
			bool found_permuts = false;
			if(aux == "TP" && count_products >= 3 && (size_numbers - 5) >= 12){
				int left_size = size_numbers - 5;
				if(aux2[left_size] != '0'){
					vector<int> possib;
					if(count_products == 3){
						for(j = 0; j < count_products; j++){
							possib.push_back(4);
						}
						if(left_size == 12){
							vector<int> auxiliar;
							string s = "";
							int l;
							int count_vec = 0, count_aux;
							for(l = 0; l < count_products; l++){
								int n_casas = possib[l];
								for(count_aux = count_vec; count_aux < n_casas + count_vec; count_aux++){
									s += aux2[count_aux];
								}
								count_vec += n_casas; 
								auxiliar.push_back(stoi(s));
								s = "";
							} 
							for(count_aux = count_vec; count_aux < count_vec+5; count_aux++){
								s+=aux2[count_aux];
							}
							int total_sum = 0;
							for(count_aux = 0; count_aux < count_products; count_aux++){
								total_sum+=(auxiliar[count_aux]);
							}
							if(total_sum == stoi(s)){
								possibilities[count_seller].push_back(auxiliar);
								found_permuts = true;
							}
						}
					}
					else if(count_products == 4){
						possib.push_back(0);
						for(j = 1; j < count_products; j++){
							possib.push_back(4);
						}
						int sum = 12;
						for(j = 1; j <= 4; j++){
							possib[0] = j;
							sum++; //ce ta fazendo um sum++, ou seja, a soma so aumenta. se chegou nela, para de boas que nao  vai encontrar mais no loop.
							if(left_size == sum){
								do{
									vector<int> auxiliar;
									string s = "";
									int l;
									int count_vec = 0, count_aux;
									for(l = 0; l < count_products; l++){
										int n_casas = possib[l];
										for(count_aux = count_vec; count_aux < n_casas + count_vec; count_aux++){
											s += aux2[count_aux];
										}
										count_vec += n_casas; 
										auxiliar.push_back(stoi(s));
										s = "";
									} 
									for(count_aux = count_vec; count_aux < count_vec+5; count_aux++){
										s+=aux2[count_aux];
									}
									int total_sum = 0;
									for(count_aux = 0; count_aux < count_products; count_aux++){
										total_sum+=(auxiliar[count_aux]);
									}
									if(total_sum == stoi(s)){
										possibilities[count_seller].push_back(auxiliar);
										found_permuts = true;
									}
								}while(next_permutation(possib.begin(), possib.end()));
								break;
							}
						}
					}
					else{
						possib.push_back(2);
						possib.push_back(3);
						possib.push_back(3);
						possib.push_back(4);
						possib.push_back(4);

						int sum = 2+3+3+4+4;

						if(sum == left_size){
							do{
								vector<int> auxiliar;
								string s = "";
								int l;
								int count_vec = 0, count_aux;
								for(l = 0; l < count_products; l++){
									int n_casas = possib[l];
									for(count_aux = count_vec; count_aux < n_casas + count_vec; count_aux++){
										s += aux2[count_aux];
									}
									count_vec += n_casas; 
									auxiliar.push_back(stoi(s));
									s = "";
								} 
								for(count_aux = count_vec; count_aux < count_vec+5; count_aux++){
									s+=aux2[count_aux];
								}
								int total_sum = 0;
								for(count_aux = 0; count_aux < count_products; count_aux++){
									total_sum+=auxiliar[count_aux];
								}
								if(total_sum == stoi(s)){
									possibilities[count_seller].push_back(auxiliar);
									found_permuts = true;
								}
							}while(next_permutation(possib.begin(), possib.end()));
						}

						if(!found_permuts){  
							possib = {3, 3, 4, 4, 4};
							sum++;

							if(sum == left_size){
								do{
									vector<int> auxiliar;
									string s = "";
									int l;
									int count_vec = 0, count_aux;
									for(l = 0; l < count_products; l++){
										int n_casas = possib[l];
										for(count_aux = count_vec; count_aux < n_casas + count_vec; count_aux++){
											s += aux2[count_aux];
										}
										count_vec += n_casas; 
										auxiliar.push_back(stoi(s));
										s = "";
									} 
									for(count_aux = count_vec; count_aux < count_vec+5; count_aux++){
										s+=aux2[count_aux];
									}
									int total_sum = 0;
									for(count_aux = 0; count_aux < count_products; count_aux++){
										total_sum+=(auxiliar[count_aux]);
									}
									if(total_sum == stoi(s)){
										possibilities[count_seller].push_back(auxiliar);
										found_permuts = true;
									}
								}while(next_permutation(possib.begin(), possib.end()));
							}

							if(!found_permuts){
								possib = {1, 0, 4, 4, 4}; //1 1, 1 2, 1 3 4 4 4

								sum = 13;
								for(j = 1; j <= 3; j++){
									possib[1] = j;
									sum++; //idem, soma so aumenta

									if(sum == left_size){
										do{
											vector<int> auxiliar;
											string s = "";
											int l;
											int count_vec = 0, count_aux;
											for(l = 0; l < count_products; l++){
												int n_casas = possib[l];
												for(count_aux = count_vec; count_aux < n_casas + count_vec; count_aux++){
													s += aux2[count_aux];
												}
												count_vec += n_casas; 
												auxiliar.push_back(stoi(s));
												s = "";
											} 
											for(count_aux = count_vec; count_aux < count_vec+5; count_aux++){
												s+=aux2[count_aux];
											}
											int total_sum = 0;
											for(count_aux = 0; count_aux < count_products; count_aux++){
												total_sum+=(auxiliar[count_aux]);
											}
											if(total_sum == stoi(s)){
												possibilities[count_seller].push_back(auxiliar);
												found_permuts = true;
											}
										}while(next_permutation(possib.begin(), possib.end()));
										break;
									}

									if(!found_permuts){ //2 2, 2 3 4 4 
										possib = {2, 1, 4, 4, 4};
										sum = 15;

										for(j = 2; j <= 3; j++){
											possib[1] = j;
											sum++;

											if(sum == left_size){
												do{
													vector<int> auxiliar;
													string s = "";
													int l;
													int count_vec = 0, count_aux;
													for(l = 0; l < count_products; l++){
														int n_casas = possib[l];
														for(count_aux = count_vec; count_aux < n_casas + count_vec; count_aux++){
															s += aux2[count_aux];
														}
														count_vec += n_casas; 
														auxiliar.push_back(stoi(s));
														s = "";
													} 
													for(count_aux = count_vec; count_aux < count_vec+5; count_aux++){
														s+=aux2[count_aux];
													}
													int total_sum = 0;
													for(count_aux = 0; count_aux < count_products; count_aux++){
