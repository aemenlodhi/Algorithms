//exercise 2 of KT 

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

struct week{

	int l=0;
	int h=0;

};

int opt(vector<int>& memo, int i){

	if(i<0)
		return 0;

	else
		return memo[i];

}

int processCase(vector<week>& d){

	vector<int> memo(d.size(),0);	
	
	for(int i=0;i<d.size();i++)
		cout<<d[i].l<<"\t"<<d[i].h<<endl;
	

	memo[0]=max(d[0].h,d[0].l);

	printf("mem 0 is: %d\n",memo[0]);

	for(int j=1;j<d.size();j++){

		memo[j]=max(d[j].h+opt(memo,j-2),max(d[j].l+opt(memo,j-1),opt(memo,j-1)));
		printf("mem %d is: %d\n",j,memo[j]);

	}	
	
	return memo[d.size()-1];

}

int main(){

	int numWeeks=0;
	scanf("%d\n",&numWeeks);

	vector<week> datum;
	week w;

	while(numWeeks--){

		scanf("%d %d\n",&w.l,&w.h);
		datum.push_back(w);		

	}

	printf("Max revenue: %d\n",processCase(datum));

	return 0;
}
