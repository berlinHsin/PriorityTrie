#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std ;

struct Node{
	string data ;
	bool priority ;
	Node *left ;
	Node *right ;
};

Node* root = NULL; 
Node* create_node(string);
Node* insert(Node*,Node*);
vector<string> input();
vector<string> sort();
bool include(string,string);
bool match(string,string);
string search(string);

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


int main(){
	vector<string> prefix = input();
	int size = prefix.size();
	for(int i = 0 ; i < size ; i++){
		root = insert(root,prefix[i],0);
	}
	string search_string = "01010011000000001111111100000000" ;
	string BMP = search(search_string);
	cout<<BMP<<endl;
}
