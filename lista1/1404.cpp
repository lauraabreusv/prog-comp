// https://www.beecrowd.com.br/judge/pt/problems/view/1404

/** 

You should simulate a round of a king of checkers where the player
can move front and back. The goal of the simulation is to identify 
the biggest amount of pieces of the oponent player you can capture 
in one round.

**/

#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>

using namespace std;

class node{
public:
	int state;
	int left_down;
	int left_up;
	int right_down;
	int right_up;
};

int max_element(vector<int> a){
	int max = 0;
	vector<int>::iterator it;
	for(it = a.begin(); it != a.end(); it++){
		if(*it > max) max = *it;
	}
	return max;
}

int find_max(vector<node> positions, int pos){

	vector<int> maxs;
	bool empty = true;

	if(positions[pos].left_down != -1){
		int p2 = positions[pos].left_down;
		if(positions[p2].state == 2 && positions[p2].left_down != -1){
			int new_pos = positions[p2].left_down;
			if(positions[new_pos].state == 0){
				positions[pos].state = 0;
				positions[p2].state = 0;
				positions[new_pos].state = 1;

				maxs.push_back(find_max(positions, new_pos));
				empty = false;

				positions[pos].state = 1;
				positions[p2].state = 2;
				positions[new_pos].state = 0;
			}
		}
	}
	if(positions[pos].right_down != -1){
		int p2 = positions[pos].right_down;
		if(positions[p2].state == 2 && positions[p2].right_down != -1){
			int new_pos = positions[p2].right_down;
			if(positions[new_pos].state == 0){
				// vector<node> positions = positions;
				positions[pos].state = 0;
				positions[p2].state = 0;
				positions[new_pos].state = 1;

				maxs.push_back(find_max(positions, new_pos));
				empty = false;
			}
		}
	}	
	if(positions[pos].left_up != -1){
		int p2 = positions[pos].left_up;
		if(positions[p2].state == 2 && positions[p2].left_up != -1){
			int new_pos = positions[p2].left_up;
			if(positions[new_pos].state == 0){
				positions[pos].state = 0;
				positions[p2].state = 0;
				positions[new_pos].state = 1;

				maxs.push_back(find_max(positions, new_pos));
				empty = false;
			}
		}
	}	
	if(positions[pos].right_up != -1){
		int p2 = positions[pos].right_up;
		if(positions[p2].state == 2 && positions[p2].right_up != -1){
			int new_pos = positions[p2].right_up;
			if(positions[new_pos].state == 0){
				positions[pos].state = 0;
				positions[p2].state = 0;
				positions[new_pos].state = 1;

				maxs.push_back(find_max(positions, new_pos));
				empty = false;
			}
		}
	}

	if(empty){
		return 0;
	}
	else{
		return 1 + max_element(maxs);
	}
}

int main(){

	int lines, columns;
	cin>>lines>>columns;

	while(lines && columns){
		int i;
		vector<node> positions;
		node head;
		head.state = -1;
		positions.push_back(head);

		int line = 1, column = 1;
		if(columns%2 == 1){
			for(i = 1; i <= ceil((float)(lines*columns)/2); i++){
				int st;
				cin>>st;
				node current;
				current.state = st;
				if(line != 1 && column != 1){
					current.left_down = i - ceil((float)columns/2);
				}else{
					current.left_down = -1;
				}
				if(line != 1 && column != columns){
					current.right_down = i - ceil((float)columns/2) + 1;
				}else{
					current.right_down = -1;
				}
				if(line != lines && column != 1){
					current.left_up = i + ceil((float)columns/2) - 1;
				}else{
					current.left_up = -1;
				}
				if(line != lines && column != columns){
					current.right_up = i + ceil((float)columns/2);
				}else{
					current.right_up = -1;
				}
				positions.push_back(current);

				if(column == columns){
					line++; 
					column = 2;

				}
				else if(column == columns - 1){
					line++;
					column = 1;
				}
				else{
					column+=2;
				}
			}
		}
		else{
			for(i = 1; i <= ceil((float)(lines*columns)/2); i++){
				int st;
				cin>>st;
				node current;
				current.state = st;
				if(line%2 == 0){ 
					if(line != 1 && column != 1){
						current.left_down = i - columns/2;
					}
					else{
						current.left_down = -1;
					}
					if(line != 1 && column != columns){
						current.right_down = i - (columns/2) + 1;	
					}
					else{
						current.right_down = -1;
					}
					if(line != lines && column != 1){
						current.left_up = i + (columns/2);
					}
					else{
						current.left_up = -1;
					}
					if(line != lines && column != columns){
						current.right_up = i + (columns/2) + 1;
					}
					else{
						current.right_up = -1;
					}
				}
				else{ 
					if(line != 1 && column != 1){
						current.left_down = i - (columns/2) - 1;
					}
					else{
						current.left_down = -1;
					}
					if(line != 1 && column != columns){
						current.right_down = i - (columns/2);	
					}
					else{
						current.right_down = -1;
					}
					if(line != lines && column != 1){
						current.left_up = i + (columns/2) - 1;
					}
					else{
						current.left_up = -1;
					}
					if(line != lines && column != columns){
						current.right_up = i + (columns/2);
					}
					else{
						current.right_up = -1;
					}
				}
				positions.push_back(current);

				if(column == columns){
					line++; 
					column = 1;

				}
				else if(column == columns - 1){
					line++;
					column = 2;
				}
				else{
					column+=2;
				}
			}
		}

		vector<int> maxs_casas;
		for(i = 1; i <= ceil((float)(lines*columns)/2); i++){
			if(positions[i].state == 1){
				vector<node> positions_aux = positions;
				maxs_casas.push_back(find_max(positions_aux, i));
			}
		}

		cout<<max_element(maxs_casas)<<endl;
		cin>>lines>>columns;
	}

	return 0;
}