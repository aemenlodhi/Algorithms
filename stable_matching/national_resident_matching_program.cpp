#include<queue>
#include<utility>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stdio.h>
#include<list>

using namespace std;

enum DOCTOR_STATUS{

	FREE,
	HIRED
	

};

enum HOSPITAL_STATUS{

	FREE_SLOTS,
	COMMITTED	

};

struct priorityData{

	string name;
	int rank;

	bool operator<(const priorityData& right)const{

		if(rank<right.rank)
			return true;
		else
			return false;
	
	}

};



class doctor{

public:
	string name;
	DOCTOR_STATUS status;
	string match;

	list<string> preferences;
	map<string,unsigned int> hospitalRanking;

	doctor():name("A"),status(FREE),match("NULL"){}
	bool hasAppliedAtAllHospitals()const;

};

bool doctor::hasAppliedAtAllHospitals()const{

	if(preferences.empty())
		return true;
	else
		return false;

}

class hospital{

	public:
		string name;
		HOSPITAL_STATUS status;
		unsigned int numVacancies;
		list<string> preferences;
		map<string,unsigned int> doctorRanking;
		std::priority_queue<priorityData> match;
	
		hospital():status(FREE_SLOTS),numVacancies(0){}

};

bool isFreeDoctorAvailable(const map<string,doctor>& m){

	for(map<string,doctor>::const_iterator itM=m.begin();itM!=m.end();itM++)
		if(itM->second.status==FREE && !itM->second.hasAppliedAtAllHospitals())
			return true;
	
	return false;

}

bool isSlotAtHospitalAvailable(const map<string,hospital>& h){

	for(map<string,hospital>::const_iterator itH=h.begin();itH!=h.end();itH++)
		if(itH->second.status==FREE_SLOTS)
			return true;
	
	return false;
}

void formStableMatches(map<string,doctor>& m, map<string,hospital>& n){

	string other;
	while(isFreeDoctorAvailable(m)){
		
		for(map<string,doctor>::iterator itM=m.begin();itM!=m.end();itM++)
			if(itM->second.status==FREE && !itM->second.hasAppliedAtAllHospitals()){
				
				other=itM->second.preferences.front();
				itM->second.preferences.pop_front();

				if(n[other].status==FREE_SLOTS){
			

					//cout<<"Doc "<<itM->first<<" joined Hop "<<other<<endl;	
						
					itM->second.status=HIRED;
					itM->second.match=other;

					priorityData d;
					d.name=itM->second.name;
					d.rank=n[other].doctorRanking[itM->second.name];
					n[other].match.push(d);
					
					if(n[other].match.size()==n[other].numVacancies)
						n[other].status=COMMITTED;

				}

				else{
			
					priorityData d;
					d.name=itM->second.name;
					d.rank=n[other].doctorRanking[itM->second.name];				
					
					//cout<<"Rank of applicant doc "<<itM->first<<" at hop "<<other<<" is "<<d.rank<<endl;
					//cout<<"Rank of least rated doc "<<n[other].match.top().name<<" at hop "<<other<<" is "<<n[other].doctorRanking[n[other].match.top().name]<<endl;		

	
					if(d.rank<n[other].match.top().rank){
						
						//cout<<"Doc "<<n[other].match.top().name<<" leaving Hop "<<other<<endl;
					
						m[n[other].match.top().name].status=FREE;
						m[n[other].match.top().name].match="NULL";
			
						n[other].match.pop();
						n[other].match.push(d);

						itM->second.status=HIRED;
						itM->second.match=other;
					
						//cout<<"Doc "<<itM->first<<" joined Hop "<<other<<endl;	
		

					}
				
				}				

				break;
			}

	}

	for(map<string,doctor>::const_iterator itM=m.begin();itM!=m.end();itM++)
		cout<<"("<<itM->first<<","<<itM->second.match<<") ";
	
	cout<<endl;

}


int main(){

	int numCases;
	int numDoctors;
	int numHospitals;
	char doc[100];
	char hop[100];
	int numVacancies;
	map<string,doctor> candidates;
	map<string,hospital> facilities;
			
	scanf("%d\n",&numCases);
	//printf("Num cases: %d\n",numCases);

	for(int i=1;i<=numCases;i++){
	
		scanf("%d %d\n",&numDoctors,&numHospitals);

		//printf("NumDoctors: %d NumHospitals: %d\n",numDoctors,numHospitals);

		for(int j=0;j<numDoctors;j++){

			scanf("%s",&doc);

			candidates[doc].name=doc;

			for(int k=0;k<numHospitals;k++){
				scanf("%s",&hop);
				
				candidates[doc].preferences.push_back(hop);
				candidates[doc].hospitalRanking[hop]=k;		
			}

		}

		for(int j=0;j<numHospitals;j++){

			scanf("%s %d",&hop,&numVacancies);
			
			facilities[hop].name=hop;
			facilities[hop].numVacancies=numVacancies;

			for(int k=0;k<numDoctors;k++){
			
				scanf("%s",&doc);

				facilities[hop].preferences.push_back(doc);	
				facilities[hop].doctorRanking[doc]=k;
			}

		}	
		
		/*
		for(map<string,doctor>::iterator itD=candidates.begin();itD!=candidates.end();itD++){
			cout<<itD->first<<": ";
			
			for(list<string>::iterator itH=itD->second.preferences.begin();itH!=itD->second.preferences.end();itH++)
				cout<<*itH<<" ";
		
			cout<<endl;	
		}
			

		for(map<string,hospital>::iterator itH=facilities.begin();itH!=facilities.end();itH++){
			cout<<itH->first<<" ,  "<<itH->second.numVacancies<<" : ";
			
			for(list<string>::iterator itD=itH->second.preferences.begin();itD!=itH->second.preferences.end();itD++)
				cout<<*itD<<" ";
		
			cout<<endl;	
		}
		*/
	
		formStableMatches(candidates,facilities);	
	
	}
		
	return 0;

}
