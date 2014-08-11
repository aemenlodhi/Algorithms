#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<cstdio>

using namespace std;

typedef unsigned int ui;

struct interval{

	ui startTime;
	ui finishTime;
	ui index;	//interval id
	ui value;
	ui p;
};

struct compareInterval{

	bool operator()(const interval& i1, const interval& i2){
		return i1.finishTime<i2.finishTime;	
	}

};

ui computeMaxValue(const vector<interval>& v, const int& i, vector<ui>& M){

	if(i<0)
		return 0;

	if(M[i]!=0)
		return M[i];
	
	else
		return M[i]=max(v[i].value+computeMaxValue(v,v[i].p,M),computeMaxValue(v,i-1,M));

}

int main(){

	vector<interval> vi;
	interval ix;

	ui index, value, start, finish;
	while(scanf("%d %d %d %d",&index,&value,&start,&finish)!=EOF){

		ix.index=index;
		ix.value=value;
		ix.startTime=start;
		ix.finishTime=finish;
		vi.push_back(ix);
		
	}

	std::sort(vi.begin(),vi.end(),compareInterval());	

	ui i1, i2;
	i1=vi.size()-1;

	for(vector<interval>::reverse_iterator it=vi.rbegin();it!=vi.rend();++it,i1--){
		i2=i1-1;
		for(vector<interval>::reverse_iterator it2=it+1;it2!=vi.rend();++it2,i2--){
	
			if((*it2).finishTime<(*it).startTime && it!=it2){

				(*it).p=i2;
				break;
			}		

		}

	}

	vi[0].p=-1;	

	vector<ui> M(vi.size(),0);

	for(ui i=0;i<vi.size();i++)
		M[i]=0;

	printf("Max value is: %d\n",computeMaxValue(vi,vi.size()-1,M));
		
	return 0;

}
