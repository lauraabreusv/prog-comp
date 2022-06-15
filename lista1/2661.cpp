// https://www.beecrowd.com.br/judge/pt/problems/view/2661

/**

Compute if a number can be decomposed in a product of two or more prime numbers
without any repetition

**/

#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

bool is_prime(vector<long long> factors, long long n){
	int i;
	long long max = sqrt(n);
	int size = factors.size();
	for(i = 0; i < size; i++){
		if(factors[i] > max) return true;
		if(n%factors[i] == 0) return false;
	}
	return true;
}

int main(){
	long long n;
	cin>>n;

	long long max = sqrt(n);
	long long i;

	vector<long long> primes;

	int count = 0;

	bool found = false;

	if(n%2 == 0){
		count++;
		n/=2;
		max = sqrt(n);
		while(n%2 == 0){
			n/=2;
			max = sqrt(n);
		}
	}

	for(i = 3; i <= max; i+=2){
		if(n%i == 0 && is_prime(primes, i)){
			count++;
			primes.push_back(i);
			n/=i;
			max = sqrt(n);
			while(n%i == 0){
				n/=i;
				max = sqrt(n);
			}
		}
	}

	if(n > 2){
		count++;
	}

	cout<<pow(2,count) - count - 1<<endl;
	return 0;
}