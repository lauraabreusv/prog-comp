// https://www.beecrowd.com.br/judge/pt/problems/view/1082
/**

List each one of the connected components of a given graph.

**/


#include <iostream>
#include <vector> 
#include <list>

using namespace std;

#define conversion 97

class Node{
public:
	 bool visited;
	 list<int> adjacency;
	 int component;
};

void find_cc(vector<Node> &g, int cc, int pos){
	if(g[pos].visited == false){
		g[pos].component = cc;
		g[pos].visited = true;
		list<int>::iterator it;
		for(it = g[pos].adjacency.begin(); it != g[pos].adjacency.end(); it++){
			find_cc(g, cc, *it);
		}
	}
	return;
}

int main(){

	int n; 
	int v, e; 
	int i;
	cin>>n;
	for(i = 1; i <= n; i++){
		cin>>v>>e; 
		vector<Node> graph;
		int j;
		for(j = 0; j < v; j++){
			Node node;
			node.visited = false;
			node.component = 0;
			graph.push_back(node);
		}

		for(j = 0; j < e; j++){
			char v1, v2;
			cin>>v1>>v2;
			graph[int(v1) - conversion].adjacency.push_back(int(v2) - conversion);
			graph[int(v2) - conversion].adjacency.push_back(int(v1) - conversion);
		}

		int cc = 0;
		for(j = 0; j < v; j++){
			if(graph[j].visited == false){
				cc++;
				find_cc(graph, cc, j);
			}
		}
		cout<<"Case #"<<i<<":"<<endl;
		int k;
		for(k = 1; k <= cc; k++){
			for(j = 0; j < v; j++){
				if(graph[j].component == k){
					cout<<char(j+conversion)<<",";
				}
			}
			cout<<endl;
		}
		cout<<cc<<" connected components"<<endl<<endl;
	}
	return 0;
}