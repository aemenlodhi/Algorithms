#include<vector>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<limits>

using namespace std;

typedef unsigned int ui;

ui change(ui val, vector<ui>& memo, vector<ui>& coins){

	if(val==0)
		return val;

	if(memo[val]!=0)
		return memo[val];

	ui minCount=std::numeric_limits<unsigned int>::max();
	ui count=0;	

	for(ui i=0;i<coins.size();i++){
		
		if(coins[i]>val)
			break;
		
		count=change(val-coins[i],memo,coins);
		if(count<minCount){
			minCount=count;
		}
		
	}

	return memo[val]=1+count;
}

int processCase(ui val, vector<ui> coins){

	vector<ui> memo(val+1,0);
	
	return change(val,memo,coins);

}

int main(){

	ui val,numCoins;

	scanf("%d\n%d\n",&val,&numCoins);
	vector<ui> coins(numCoins,0);

	for(ui i=0;i<numCoins;i++)
		scanf("%d",&coins[i]);

	printf("Min number of coins: %d\n",processCase(val,coins));


	return 0;
}
