// https://www.beecrowd.com.br/judge/pt/problems/view/2784

/**

Considering that there are a lot of islands and people that leave in all of them
play an online game, calculate the difference of "pings" between the island closer
to the server and the farthest from it. Ping is the time the signal takes to pass 
from an island to another.

**/

#include <iostream> 
#include <vector> 
#include <list>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;

class Edge{
public:
	bool visited;
	int node; 
	int weigth;
};

class Node{
public:
	 bool visited;
	 int number;
	 list<Edge> adjacency;
};

vector<int> dijkstra(vector<Node>&graph, int origen, int n_nodes){ 
	vector<int> d;

	int i;
	for(i = 0; i < n_nodes; i++){
		d.push_back(100000); 
	}

	d[origen - 1] = 0;

	vector<int> q;
	for(i = 0; i < n_nodes; i++){
		q.push_back(i);
	}



	while(!q.empty()){

		vector<int>::iterator it;
		int u = 100000;
		int pos_u;
		int erase_pos;
		int count = 0;
		for(it = q.begin(); it != q.end(); it++){
			if(d[*it] < u){
				u = d[*it];
				pos_u = *it;
				erase_pos = count; 
			}
			count++;
		}

		q.erase(q.begin() + erase_pos); 

		list<Edge>::iterator it_adj;
		for(it_adj = graph[pos_u].adjacency.begin(); it_adj != graph[pos_u].adjacency.end(); it_adj++){
			if(d[it_adj->node - 1] > d[pos_u] + it_adj->weigth){
				d[it_adj->node - 1] = d[pos_u] + it_adj->weigth;
			}
		}
	}

	return d;
}

int main(){
	int n_nodes, n_edges;
	cin>>n_nodes>>n_edges;
	int i;

	vector<Node> graph;
	for(i = 1; i <= n_nodes; i++){ 
		Node node;
		node.visited = false;
		node.number = i;
		graph.push_back(node);
	}

	int node1, node2, ping;
	for(i = 0; i < n_edges; i++){
		cin>>node1>>node2>>ping;
		Edge edge1;
		edge1.visited = false;
		edge1.node = node2;
		edge1.weigth = ping;
		graph[node1 - 1].adjacency.push_back(edge1);

		Edge edge2;
		edge2.visited = false;
		edge2.node = node1;
		edge2.weigth = ping;
		graph[node2 - 1].adjacency.push_back(edge2);
	}

	int server;
	cin>>server; 

	vector<int> distances = dijkstra(graph, server, n_nodes);

	int max = -1; 
	int min = 1000000;
	for(i = 0; i < n_nodes; i++){
		if(distances[i] > max){
			max = distances[i];
		}
		if(distances[i] < min && distances[i] != 0){
			min = distances[i];
		}
	}

	cout<<max - min<<endl;

	return 0;
}