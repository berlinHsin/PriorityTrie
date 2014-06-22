#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std ;

struct Node{
	string data ;
	Node *left ;
	Node *right ;
};

Node* create_node(string);
Node* insert(Node*,Node*);

Node* insert(Node* node , string value , int level){
	if(node==NULL){
		node = create_node(value);
	}else{
		value.c_str();
		int test = value[level];
		if(test==48){
			value.assign(value);
			node->left = insert(node->left,value,++level);
		}else{
			value.assign(value);
			node->right = insert(node->right,value,++level);
		}
	}
	return node ;
}

Node* create_node(string value){
	Node* n = (Node*)malloc(sizeof(Node));
	n -> data = value ;
	n -> left = NULL ;
	n -> right = NULL ;
	return n ; 
}

int main(){
	Node* root = NULL; 
	root = insert(root,"10011",0);
	root = insert(root,"1101",0);
	root = insert(root,"0001",0);
	cout<<root->data<<endl;
	cout<<root->left->data<<endl;
}
