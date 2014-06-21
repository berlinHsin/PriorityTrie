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

std::vector<std::string> sort(std::vector<std::string> ip){
	int size = ip.size();
	for(int i =0 ; i<size ; i++){
		int length = ip[i].size() ;
		int index  = i  ;
		for(int j =i ;j<size;j++){
			if(ip[j].size()>length){
				index = j ;
				length = ip[j].size();
			}
		}
		if(i!= index){
			std::swap(ip[i],ip[index]);
		}
	}
	return ip ;
}

std::vector<std::string> input(){
	std::vector<std::string> ip ;
	std::string line ;
	std::ifstream fp("address.txt");
	while(std::getline(fp,line)){
		ip.push_back(line);
	}
	fp.close();
	ip = sort(ip);
	return ip ;
}

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
