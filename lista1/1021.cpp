// https://www.beecrowd.com.br/judge/pt/problems/view/1021
/**

Read a value of a floating point with two decimal cases. This value represents a monetary value.
Calculate the smallest number of bills and coins in which this value could be paid.
Bills are of 100, 50, 20, 10, 5 and 2 and coins are of 1, 0.50, 0.25, 0.10, 0.05, 0.01.


**/


#include <iostream>
#include <cmath> 
#include <iomanip> 
#include <math.h>

using namespace std;

int main(){

	double value;
	cin>>value;

	double notas[6] {100, 50, 20, 10, 5, 2};
	double moedas[6] = {1, 0.50, 0.25, 0.10, 0.05, 0.01};

	double num_notas[6];
	double num_moedas[6]; 

	cout<<"NOTAS:"<<endl;
	int i;
	for(i = 0; i < 6; i++){

		num_notas[i] = trunc(value/notas[i]);
		value -= num_notas[i]*notas[i];
		value = round(value*100)/100;
		cout<<num_notas[i]<<" nota(s) de R$ "<<notas[i]<<".00"<<endl;
	}

	num_moedas[0] = trunc(value/moedas[0]);
	value -= num_moedas[0]*moedas[0];
	value = round(value*100)/100;


	for(i = 1; i < 6; i++){
		num_moedas[i] = trunc(value/moedas[i]);
		value -= num_moedas[i]*moedas[i];
		value = (round(value*100))/100;
	}

	cout<<"MOEDAS:"<<endl;
	cout<<num_moedas[0]<<" moeda(s) de R$ "<<"1.00"<<endl;
	cout<<num_moedas[1]<<" moeda(s) de R$ "<<"0.50"<<endl;
	cout<<num_moedas[2]<<" moeda(s) de R$ "<<"0.25"<<endl;
	cout<<num_moedas[3]<<" moeda(s) de R$ "<<"0.10"<<endl;
	cout<<num_moedas[4]<<" moeda(s) de R$ "<<"0.05"<<endl;
	cout<<num_moedas[5]<<" moeda(s) de R$ "<<"0.01"<<endl;
	return 0;
}