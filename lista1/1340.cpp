// https://www.beecrowd.com.br/judge/pt/problems/view/1340

/**

Guess if the data structure is either a queue, either a priority queue,
either a stack, neither or can be more than one of them, given the sequence
of elemtns entrering and leaving the structure. 1 is for the element entering,
2 is for it leaving.

**/

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main(){

	int n;
	while(cin>>n){
		bool queue = true;
		bool priority = true;
		bool stack = true;

		int i;
		int command, x;
		list<int> bag;
		list<int>::iterator it;
		int max;
		for(i = 0; i < n; i++){
			cin>>command>>x;
			if(command == 1){
				bag.push_back(x);
			}
			else{
				if(!queue && !priority && !stack) continue;
				it = bag.begin();
				if(queue && x != *it){
					 queue = false;
				}
				if(priority){
					int max = -1;
					for(it = bag.begin(); it != bag.end(); it++){
						if(*it > max){
							max = *it;
						} 
					}
					if(max != x) priority = false;
				}
				if(stack && x != bag.back()){
					stack = false;
				}


				if(stack){
					bag.pop_back();
				}
				else{
					for(it = bag.begin(); it != bag.end(); it++){
						if(*it == x){
							bag.erase(it);
							break;
						}
					}
				}
			}
		}
		if(!queue && !priority && !stack) cout<<"impossible"<<endl;
		else if(!queue && !priority && stack) cout<<"stack"<<endl;
		else if(!queue && priority && !stack) cout<<"priority queue"<<endl;
		else if(queue && !priority && !stack) cout<<"queue"<<endl;
		else cout<<"not sure"<<endl;

	}

	return 0;
}