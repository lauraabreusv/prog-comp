//https://www.beecrowd.com.br/judge/pt/problems/view/1194

/**

Given the prefix and infix paths of a binary tree, compute the postfix path.

**/

#include <iostream>
#include <string> 

using namespace std;

class Node{
public:
	char value;
	Node *left;
	Node *right;
	Node *parent;
	bool is_right; 
	bool visited;
};

class Tree{
public:
	Node *root;
};


Tree create_tree(string s1, string s2, int size){
	Node *root = (Node*)malloc(sizeof(Node)); 
	root->value = s1[0];
	root->right = NULL;
	root->left = NULL;
	root->parent = NULL;
	root->is_right = false;
	root->visited = false;

	Tree *tree = (Tree*)malloc(sizeof(Tree));
	tree->root = root;

	Node *current_node = root;

	int i;
	for(i = 1; i < size; i++){
		Node *new_node = (Node*)malloc(sizeof(Node));
		new_node->value = s1[i];
		new_node->right = NULL;
		new_node->left = NULL;
		new_node->parent = NULL;
		new_node->is_right = false;
		new_node->visited = false;
		int j;
		for(j = 0; j < size; j++){
			if(s2[j] == new_node->value){ 
				if(new_node->is_right == false){ 
					current_node->left = new_node;
				}
				else{ 
					current_node = current_node->left;
					while(current_node->right != NULL){
						current_node = current_node->right;
					}
					current_node->right = new_node;
				}
				new_node->parent = current_node;
				current_node = new_node;
				break;
			}

			else if(s2[j] == current_node->value){
				new_node->is_right = true; 

				while(current_node->is_right){ 
					current_node = current_node->parent;
				}
				if(current_node->parent != NULL){
					current_node = current_node->parent;
					j = 0; 
				}
				else{
					while(current_node->right != NULL){
						current_node = current_node->right;
					}
					current_node->right = new_node;
					new_node->parent = current_node;
					current_node = new_node;
					break;
				}
			}
		}
	}
	return *tree; 
}

void post_order(Node *node){
	if(node->left != NULL && node->left->visited == false){
		post_order(node->left);
	}
	else if(node->right != NULL && node->right->visited == false){
		post_order(node->right);
	}
	else{
		cout<<node->value;
		node->visited = true;
		if(node->parent != NULL){
			post_order(node->parent);
		}
	}
	return; 
}

int main(){
	int num_cases;
	cin>>num_cases;
	int i;
	for(i = 0; i < num_cases; i++){
		int size;
		string s1, s2;
		cin>>size>>s1>>s2;

		int j;
		Tree tree = create_tree(s1, s2, size); 

		post_order(tree.root); 
		cout<<endl;
	}
	return 0;
}
