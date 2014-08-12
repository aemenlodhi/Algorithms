#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<limits>

using namespace std;

typedef int ui;

int maxLengthSubsequence(const vector<ui>& iv){

	vector<int> indices(iv.size(),-1);
	int maxVal;
	int maxIndex;

	for(ui i=iv.size()-1;i>0;i--){
		maxVal=-1;
		maxIndex=-1;
		for(int j=i-1;j>=0;j--){
				
			if(iv[j]<iv[i] && iv[j]>maxVal){
				maxVal=iv[j];
				maxIndex=j;
			}

		}

		indices[i]=maxIndex;
	}


	vector<ui> lsLength(iv.size(),1);
	int maxLength=0;

	for(ui i=1;i<iv.size();i++){

		if(indices[i]!=-1){
			lsLength[i]=1+lsLength[indices[i]];
				
			if(lsLength[i]>maxLength)
				maxLength=lsLength[i];
		}

	}

	return maxLength;
}

int main(){

	vector<ui> input;
	ui temp;
	while(scanf("%d\n",&temp)!=EOF){
	
		input.push_back(temp);

	}

	printf("Max increasing subsequence length is: %d\n",maxLengthSubsequence(input));


}
