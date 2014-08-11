#include "unionFindDisjointSet.h"
#include<iostream>
#include<vector>

using namespace std;

int main(){


	unionFindSet s1;
	
	for(unsigned int i=0;i<6;i++)
		s1.makeSet(i);


	for(unsigned int i=0;i<6;i++)
		cout<<s1.findSet(i)<<"\t";
	cout<<endl;

	
	s1.unionSet(1,2);
	s1.unionSet(4,5);	
	s1.unionSet(5,1);

	for(unsigned int i=0;i<6;i++)
		cout<<s1.findSet(i)<<"\t";
	cout<<endl;


	cout<<s1.isSameSet(3,2)<<endl;


}
