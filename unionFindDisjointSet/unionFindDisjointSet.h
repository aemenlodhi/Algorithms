#include<vector>

using namespace std;

class Node{

	int id;
	int parent;
	int root;
	int rank;

public:
	Node():id(-1),parent(-1),root(-1),rank(-1){}
	Node(int x):id(x),parent(x),root(x),rank(x){}
	void setId(int);
	void setParent(int);
	void setRoot(int);
	void setRank(int);

	int getId();
	int getParent();
	int getRoot();
	int getRank(); 
	
	bool operator==(const Node& rhs){
		
		if(id==rhs.id && parent==rhs.parent && root==rhs.root)
			return true;
		else
			return false;
	}
	
};

inline void Node::setId(int x){id=x;}
inline void Node::setParent(int x){parent=x;}
inline void Node::setRoot(int x){root=x;}
inline void Node::setRank(int x){rank=x;}

inline int Node::getId(){return id;}
inline int Node::getParent(){return parent;}
inline int Node::getRoot(){return root;}
inline int Node::getRank(){return rank;}

class unionFindSet{

	int numSets;
	std::vector<Node> elements;

public:
	unionFindSet():numSets(0){}
	void makeSet(int);
	void unionSet(int,int);
	int findSet(int);
	bool isSameSet(int,int);	

};

void unionFindSet::makeSet(int x){
	
	Node newElem(x);
	numSets+=1;
	elements.push_back(newElem);
	
}

int unionFindSet::findSet(int x){

	if(elements[x].getParent()!=elements[x].getId())
		elements[x].setParent(findSet(elements[x].getParent()));

	return elements[x].getParent();

}

bool unionFindSet::isSameSet(int x, int y){

	if(findSet(x)==findSet(y))
		return true;
	else
		return false;

}

void unionFindSet::unionSet(int x, int y){

	int xRoot=findSet(x);
	int yRoot=findSet(y);

	if(xRoot==yRoot)
		return;

	numSets-=1;
	if(elements[xRoot].getRank()<elements[yRoot].getRank()){
		elements[xRoot].setParent(elements[yRoot].getRoot());
	}

	else if(elements[xRoot].getRank()>elements[yRoot].getRank()){
		elements[yRoot].setParent(elements[xRoot].getRoot());
	}

	else{
		elements[yRoot].setParent(elements[xRoot].getRoot());
		elements[xRoot].setRank(elements[xRoot].getRank()+1);
	}

}
