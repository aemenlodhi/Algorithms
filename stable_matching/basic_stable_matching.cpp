#include<utility>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stdio.h>
#include<list>

using namespace std;

enum STATUSES{

	FREE,
	ENGAGED,
	COMMITTED

};

class candidate{

public:
	string name;
	STATUSES status;
	string match;

	list<string> preferences;
	map<string,unsigned int> othersData;

	candidate():name("A"),status(FREE),match("NULL"){}
	bool hasProposedAllOthers()const;

};

bool candidate::hasProposedAllOthers()const{

	if(preferences.empty())
		return true;
	else
		return false;

}

bool isFreeManAvailable(const map<string,candidate>& m){

	for(map<string,candidate>::const_iterator itM=m.begin();itM!=m.end();itM++)
		if(itM->second.status==FREE && !itM->second.hasProposedAllOthers())
			return true;
	
	return false;

}

void formStableMatches(map<string,candidate>& m, map<string,candidate>& n){

	if(m.size()!=n.size()){
		printf("Number of entities in both parties is different.\n");
		return;
	}
	
	string other;
	while(isFreeManAvailable(m)){

		for(map<string,candidate>::iterator itM=m.begin();itM!=m.end();itM++)
			if(itM->second.status==FREE && !itM->second.hasProposedAllOthers()){
				
				other=itM->second.preferences.front();
				itM->second.preferences.pop_front();

				if(n[other].status==FREE){
				
					itM->second.status=ENGAGED;
					n[other].status=ENGAGED;
					itM->second.match=other;
					n[other].match=itM->second.name;
				
				}

				else{
					
					if(n[other].othersData[n[other].match]>n[other].othersData[itM->second.name]){

						m[n[other].match].status=FREE;
						m[n[other].match].match="NULL";
						itM->second.status=ENGAGED;
						n[other].status=ENGAGED;
						itM->second.match=other;
						n[other].match=itM->second.name;
				

					}
					
				}		

				break;
			}

	}

	for(map<string,candidate>::const_iterator itM=m.begin();itM!=m.end();itM++)
		cout<<"("<<itM->first<<","<<itM->second.match<<") ";
	
	cout<<endl;

}


int main(){

	int numCases;
	int numPairs;
	char n[100];
	char en[100];
	map<string,candidate> men;
	map<string,candidate> women;
			

	scanf("%d\n",&numCases);
	printf("Num cases: %d\n",numCases);

	for(int i=1;i<=numCases;i++){
	
		scanf("%d\n",&numPairs);
		printf("Num pairs: %d\n",numPairs);

		men.clear();
		women.clear();
	
		for(int j=0;j<(2*numPairs);j++){
			
			scanf("%s",n);
		
			if(j<numPairs)
				men[n].name=n;
			else
				women[n].name=n;
			
			for(int k=0;k<numPairs;k++){
				scanf("%s",en);

				if(j<numPairs){
					men[n].preferences.push_back(en);
					men[n].othersData[en]=k;
				}
				else{
					women[n].preferences.push_back(en);
					women[n].othersData[en]=k;
				}
			}
				
		}


		for(map<string,candidate>::iterator itM=men.begin();itM!=men.end();itM++){
			cout<<itM->first<<": ";
			
			for(list<string>::iterator itS=itM->second.preferences.begin();itS!=itM->second.preferences.end();itS++)
				cout<<*itS<<" ";
			
			cout<<endl;
		}

		for(map<string,candidate>::iterator itN=women.begin();itN!=women.end();itN++){
			cout<<itN->first<<": ";
			
			for(list<string>::iterator itS=itN->second.preferences.begin();itS!=itN->second.preferences.end();itS++)
				cout<<*itS<<" ";
			
			cout<<endl;
		}

		formStableMatches(men,women);
			
	}
		
	return 0;


}
