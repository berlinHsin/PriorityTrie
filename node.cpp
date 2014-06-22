#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std ;

struct Node{
	string data ;
	bool priority ;
	bool flag ;
	Node *left ;
	Node *right ;
};

Node* root = NULL; 
Node* create_node(string);
Node* insert(Node*,Node*);
Node* search_nodeReturn(string);
vector<string> input();
vector<string> sort();
bool include(string,string);
bool match(string,string);
string search(string);
int nodeCount(Node*);
int pNodeCount(Node*);
void treeInit(Node*);
void deletion(string);
void delNode(Node*,string);

Node* insert(Node* node , string value , int level){
	if(node==NULL){
		node = create_node(value);
		if(value.size()>level){
			node->priority = true ;
		}
	}else{
		if(value.size()==level&&node->priority){
			string tmp = node->data ;
			node -> data = value ;
			node -> priority = false ;
			value = tmp ;
		}else if(value.size()>node->data.size()&&node->priority&&include(node->data,value)){
			string tmp = node->data ;
			node -> data = value ;
			node -> priority = false ;
			value = tmp ;
		}
		value.c_str();
		int p_bit = value[level];
		if(p_bit==48){
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
	n -> priority = false ;
	n -> flag = false ;
	n -> left = NULL ;
	n -> right = NULL ;
	return n ; 
}

vector<string> input(){
	vector<string> ip ;
	string line ;
	ifstream fp("address.txt");
	while(getline(fp,line)){
		ip.push_back(line);
	}
	fp.close();
	int size = ip.size();
	for(int i = 0 ; i < size ; i ++){
		int length = ip[i].size();
		int index  = i ;
		for(int j =i ;j<size;j++){
			if(ip[j].size()>length){
				index = j ;
				length = ip[j].size();
			}
		}
		if(i!=index)swap(ip[i],ip[index]);
	}
	return ip ;
}

bool include(string origin , string in ){
	int size = origin.size();
	bool result = true ;
	origin.c_str();
	in.c_str();
	for(int i = 0 ; i < size ; i++){
		if(origin[i]!=in[i]){
			result = false ;
			break ;
		}
	}
	return result ;
}

Node* search_nodeReturn(string ip){
	string bit = ip ;
	Node* node = root ;
	Node* cur  ;
	int level = 0 ;
	int p_bit ;
	bit.c_str();
	while(node!=NULL){
		if(match(node->data,ip)){
			if(node->priority)break;
		}
		p_bit = bit[level];
		if(p_bit==48){
			node = node->left ;
		}else{
			node = node->right ;
		}
		level ++ ;
	}
	return cur ;
}

string search(string ip){
	string BMP = "*" ;
	string bit = ip  ;
	Node* node = root ;
	int level = 0 ;
	int p_bit ;
	bit.c_str() ;
	while(node!=NULL){
		if(match(node->data,ip)){
			BMP = node->data ;
			if(node->priority)break;
		}
		p_bit = bit[level];
		if(p_bit==48){
			node = node->left ;
		}else{
			node = node->right ;
		}
		level ++ ;
	}
	return BMP ;
}

bool match(string node , string ip){
	bool result = true ;
	int length = node.size();
	node.c_str();
	ip.c_str();
	for(int i = 0 ; i < length ; i ++){
		if(node[i]!=ip[i]){
			result = false ;
			break ;
		}
	}
	return result ;
}

int nodeCount(Node* cur){
	int count = 1 ;
	if(cur->left!=NULL&&!cur->left->flag){
		count += nodeCount(cur->left) ;
	}
	if(cur->right!=NULL&&!cur->right->flag){
		count += nodeCount(cur->right) ;
	}
	cur->flag = true ;
	return count ;
}

void treeInit(Node* cur){
	if(cur->left!=NULL&&cur->left->flag){
		treeInit(cur->left) ;
	}
	if(cur->right!=NULL&&cur->right->flag){
		treeInit(cur->right) ;
	}
	cur->flag = false ;
}

int pNodeCount(Node* cur){
	int count = 0 ;
	if(cur->left!=NULL&&!cur->left->flag){
		count += pNodeCount(cur->left);
	}
	if(cur->right!=NULL&&!cur->right->flag){
		count += pNodeCount(cur->right);
	}
	cur->flag=true ;
	if(cur->priority){
		return count+1 ;
	}else{
		return count ;
	}
}

int main(){
	vector<string> prefix = input();
	int size = prefix.size();
	for(int i = 0 ; i < size ; i++){
		root = insert(root,prefix[i],0);
	}
	/*
	string search_string = "1000110100000001111111100000000" ;
	string BMP = search(search_string);
	cout<<BMP<<endl;
	*/
	int totalNode = nodeCount(root);
	treeInit(root);
	int pNode = pNodeCount(root);
	cout<<"Total node: "<<totalNode<<endl;
	cout<<"Priority node: "<<pNode<<endl;
	//int totalNode = nodeCount(root);
	return 0 ;
}
