#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std ;

struct node{
	std::string data ;
	node *left ;
	node *right ;
	bool priority ;
	node(std::string value){
		data = value ;
		left = NULL ;
		right = NULL;
	}
};

typedef struct node Node ;

Node *root;
root = NULL ;

void BuildNode(Node *x , std::string ip , int Level){
	if(x == NULL){
		x -> data = ip ;
		if(ip.size()>Level){
			x->priority = true ;
		}else{
			x->priority = false ;
		}
	}else{
		ip.c_str();
		if(ip[Level]==0){
			Level ++ ;
			ip.assign(ip);
			BuildNode(x->left,ip,Level);
		}else{
			Level ++ ;
			ip.assign(ip);
			BuildNode(x->right,ip,Level);
		}
	}
}

int main(){
	BuildNode(root,"101",0);
	BuildNode(root,"1110",0);
	BuildNode(root,"10111",0);
}
