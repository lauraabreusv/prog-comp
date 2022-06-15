// https://www.beecrowd.com.br/judge/pt/problems/view/1642

/** 

There are M keys on a keyboard that work and you should compute the biggest subsequence
of a text that you can type with these M characters.

**/

#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

int main(){

	int n_teclas; 
	cin>>n_teclas;
	while(n_teclas){
		string text;

		string aux; 
		cin>>aux;
		getline(cin, text);

		text = string() + aux + text;

		int i;
		int size = text.length();

		if(n_teclas >= size){
			cout<<size<<endl;
		}
		else{
			int count_it = n_teclas, max = -1;
			int current = 0;

			if(n_teclas == 1){
				i = 1;
				while(true){
					while(text[i] == text[current] && i < size){
						i++;
						count_it++;
					}
					if(count_it > max){
						max = count_it;
					}
					if(i >= size) break;
					count_it--;
					current++;
				}
			}
			else{
				map<char, int> chars; 
				map<char, int>::iterator it;
				chars[text[current]] = 1;
				for(i = 1; i < n_teclas; i++){
					it = chars.find(text[i]);
					if(it == chars.end()){
						chars[text[i]] = 1;
					}
					else{
						chars[text[i]]++;
					}
				}

				it = chars.find(text[i]);
				while(it != chars.end()){
					chars[text[i]]++;
					i++;
					count_it++;
					it = chars.find(text[i]);
				}

				while(chars.size() < n_teclas && i < size){
					it = chars.find(text[i]);
					if(it == chars.end()){
						chars[text[i]] = 1;
					}
					else{
						chars[text[i]]++;
					}
					i++;
					count_it++;
				}
				it = chars.find(text[i]);
				while(true){
					while((chars.size() < n_teclas || it != chars.end()) && i < size){ 
						if(it == chars.end()){
							chars[text[i]] = 1;
						}
						else{
							chars[text[i]]++;
						}
						count_it++;
						i++;
						it = chars.find(text[i]);
					}
					if(count_it > max){
						max = count_it;
					}
					if(i >= size){
						break;
					}

					if(chars[text[current]] > 1){
						chars[text[current]]--;
					}
					else{
						chars.erase(text[current]);
					}
					count_it--;
					current++;
				}
			}
			cout<<max<<endl;
		}
		cin>>n_teclas;
	}
	return 0;
}