// https://www.beecrowd.com.br/judge/pt/problems/view/1357

/**

Translate digits from braille to our representation or and
vice versa. 

**/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void fill_matrix(vector<string> &lines, int i, char current){
	if(current == '1'){
		lines[i][0] = '*';
	} 
	else if(current == '2'){
		lines[i][0] = '*';
		lines[i][1] = '*';
	}
	else if(current == '3'){
		lines[i][0] = '*';
		lines[i+1][0] = '*';
	}
	else if(current == '4'){
		lines[i][0] = '*';
		lines[i+1][0] = '*';
		lines[i+1][1] = '*';
	}
	else if(current == '5'){
		lines[i][0] = '*';
		lines[i+1][1] = '*';		
	}
	else if(current == '6'){
		lines[i][0] = '*';
		lines[i+1][0] = '*';
		lines[i][1] = '*';
	}
	else if(current == '7'){
		lines[i][0] = '*';
		lines[i+1][0] = '*';
		lines[i][1] = '*';
		lines[i+1][1] = '*';
	}
	else if(current == '8'){
		lines[i][0] = '*';
		lines[i][1] = '*';
		lines[i+1][1] = '*';
	}
	else if(current == '9'){
		lines[i+1][0] = '*';
		lines[i][1] = '*';
	}
	else{
		lines[i+1][0] = '*';
		lines[i][1] = '*';
		lines[i+1][1] = '*';
	}
}

void find_number(vector<string> &matrix, int j){
	if(matrix[0][j] == '*'){
		if(matrix[0][j + 1] == '*'){
			if(matrix[1][j] == '*' && matrix[1][j+1] == '*') cout<<'7';
			else if(matrix[1][j] == '*' && matrix[1][j+1] != '*') cout<<'6';
			else if(matrix[1][j] != '*' && matrix[1][j+1] == '*') cout<<'4';
			else cout<<'3';
		}
		else if(matrix[1][j] == '*'){
			if(matrix[1][j+1] == '*') cout<<'8';
			else cout<<'2'; 
		}
		else{
			if(matrix[1][j+1] == '*') cout<<'5';
			else cout<<'1';
		}

	}
	else{
		if(matrix[1][j + 1] == '*') cout<<'0';
		else cout<<'9';
	}
}

int main(){
	int n;
	cin>>n;
	while(n){

		char language;
		cin>>language;

		int i = 0;
		int n_lines = 2*n + (n-1);

		char number;
 		if(language == 'S'){ 	
 			vector<string> lines;	
 			int count_space = 0;	
 			for(i = 0; i < n_lines; i++){
				if(count_space == 2){
					string columns = {' ', ' ', ' '};
					lines.push_back(columns);
					count_space = 0;
				}
				else{
					string columns = {'.', '.', '.'};
					lines.push_back(columns);
					count_space++;
				}
			}
			int j = 0;
			int pos = 0;
			for(i = 0; i < n; i++){
				cin>>number;
				fill_matrix(lines, pos, number);
				pos+=3;
			}

			for(j = 0; j < 3; j++){
				for(i = 0; i < n_lines; i++){
					cout<<lines[i][j];
				}
				cout<<endl;
			}
		}
		else{
			vector<string> columns;
			string line;
			getline(cin, line, '\n');

			for(i = 0; i < 3; i++){
				getline(cin, line, '\n');
				columns.push_back(line);
			} 

			int j;
			j = 0;
			while(j <= n_lines){
				find_number(columns, j);
				j+=3;
			}
			cout<<endl;
		}
		cin>>n;
	}
}