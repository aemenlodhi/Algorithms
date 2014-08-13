#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<limits>

using namespace std;

typedef int ui;

int maxLengthSubsequence(const vector<ui>& iv){

	vector<ui> lis(iv.size(),1);
	ui maxVal=1;
	ui maxLis=1;	
	
	for(ui i=1;i<iv.size();i++){
		maxVal=0;
		for(ui j=0;j<i;j++){
			if(iv[i]>iv[j] && lis[j]>maxVal)
				maxVal=lis[j];
		}
		lis[i]=1+maxVal;
	

		if(lis[i]>maxLis)
			maxLis=lis[i];
	}
	
	return maxLis;
}

int main(){

	vector<ui> input;
	ui temp;
	while(scanf("%d\n",&temp)!=EOF){
	
		input.push_back(temp);

	}

	printf("Max increasing subsequence length is: %d\n",maxLengthSubsequence(input));


}
