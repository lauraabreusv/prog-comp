// https://www.beecrowd.com.br/judge/pt/problems/view/1205

/**

Given the probability of a soldier to kill a german sniper and his number of bullets 
compute the total probability of the soldier to reach his destiny from where he his currently.
All points he has that he can cross are given and also all the paths between them and the 
number of german snipers in each one. Note that the soldier always uses the smallets path
to reach his destiny.

**/

#include <iostream> 
#include <vector> 
#include <list>
#include <iterator>
#include <cmath>
#include <iomanip>

using namespace std;

class Node{
public:
	 bool visited;
	 list<int> adjacency;
	 int n_germans; //numero de alemaes nessa posicao
};

int dijkstra(vector<Node>&graph, int origen, int destiny, int n_nodes){ 
	vector<int> weights;
	int i;
	for(i = 0; i < n_nodes; i++){
		weights.push_back(10000); 
	}
	weights[origen] = graph[origen].n_germans;

	graph[origen].visited = true;

	list<int>::iterator it;
	list<int>::iterator it_aux;
	int pos = origen;

	list <int> queue; 
	while(true){ 
		for(it = graph[pos].adjacency.begin(); it != graph[pos].adjacency.end(); it++){
			int germans_current = weights[pos] + graph[*it].n_germans;

			if(graph[*it].visited == false){
				queue.push_back(*it);
				weights[*it] = germans_current;
				graph[*it].visited = true;
			}
			else if(germans_current < weights[*it]){
				weights[*it] = germans_current;
				queue.push_back(*it);
			}
		}

		if(!queue.empty()){
			it_aux = queue.begin();
			pos = *it_aux;
			queue.pop_front();
		}
		else break;
	}
	return weights[destiny];
}

int main(){
	int n_nodes, n_edges, n_bullets;
	float prob;
	while(cin>>n_nodes>>n_edges>>n_bullets>>prob){ 
		vector <Node> graph;
		int i;
		for(i = 0; i < n_nodes; i++){
			Node node;
			node.visited = false;
			node.n_germans = 0; 
			graph.push_back(node);
		}

		int pos1, pos2;		
		for(i = 0; i < n_edges; i++){
			cin>>pos1>>pos2;
			graph[pos1 - 1].adjacency.push_back(pos2 - 1); 
			graph[pos2 - 1].adjacency.push_back(pos1 - 1);
		}

		int n_shooters;
		cin>>n_shooters;
		int pos_shooter; 
		for(i = 0; i < n_shooters; i++){
			cin>>pos_shooter;
			graph[pos_shooter - 1].n_germans++;
		}

		int origen, destiny;
		cin>>origen>>destiny;

		int n_germans_path = dijkstra(graph, origen - 1, destiny - 1, n_nodes);

		if(n_bullets < n_germans_path){
			cout<<"0.000"<<endl;
		}
		else{
			cout<<fixed;
			cout<<setprecision(3)<<pow(prob,n_germans_path)<<endl;
		}
	}
	return 0;
}

