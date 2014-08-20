#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int opt(int i, const vector<int>& d, vector<int>& memo){

	if(i>=(d.size()-1))
		return 0;

	if(memo[i]!=0)
		return memo[i];

	int maxim=0;
	return memo[i]=std::max(d[i+1],opt(i+2,d,memo));

}

int rev(const vector<int>& d){

	int max=-1,result;
	vector<int> memo(d.size(),0);
	
	for(int i=0;i<d.size()-1;i++){
	
		result=d[i]-opt(i+1,d,memo);
	
		if(result>max)max=result;
		
	}
		
	return max;

}

int main(){

	int x;
	vector<int> data;
	
	while(scanf("%d",&x)!=EOF)
		data.push_back(x);

	x=rev(data);
	if(x>0)
		printf("Max revenue: %d\n",rev(data));
	else
		printf("Dont' put your money in this stock\n");
	
	return 0;
}
