// https://www.beecrowd.com.br/judge/pt/problems/view/2653

/**

How many different strings composed by ( and ) you have. 

**/

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string pattern;
	int count = 0;
	vector<string> patterns;
	while(cin>>pattern){
		vector<string>::iterator p = find(patterns.begin(), patterns.end(), pattern);
 		if(p == patterns.end()){
 			count++;
 			patterns.push_back(pattern);
 		}
	}
	cout<<count<<endl;
	return 0;
}