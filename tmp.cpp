#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <string.h>

using namespace std ;

struct Node{

	std::string value ;
	bool flag ;
	Node *left ;
	Node *right ;

};

Node *root = NULL ;

std::vector<std::string> Sort(std::vector<std::string> ip){
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

void BuildNode(Node *node,std::string prefix , int L){
	if(node==NULL){
		node->value = prefix ;
	}	
}

void BuildPriorityTrie(std::vector<std::string> ip){
	int size = ip.size();
	ip = Sort(ip) ;
	for(int i = 0 ; i < size ; i++){
		BuildNode(root,ip[i],0);
	}
}


void Delection(){
}

void DelectNode(){
}

std::vector<std::string> Input(){
	std::vector<std::string> ip ;
	std::string line ;
	std::ifstream fp("address.txt");
	while(std::getline(fp,line)){
		ip.push_back(line);
	}
	fp.close();
	return ip ;
}

int Search(){
	return 0 ;
}

int main(){
	std::vector<std::string> ip	= Input();
	BuildPriorityTrie(ip);
	return 0 ;
}
