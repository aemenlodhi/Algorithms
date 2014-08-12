#include<vector>
#include<cstdio>
#include<algorithm>
#include<iostream>

typedef int ui;

using namespace std;

struct buttay{

	ui index;
	ui weight;
	ui value;
};

int knapsack(const vector<buttay>& input, ui w, int i, vector< vector<int> >& mw){


	if(i<0)
		return 0;
	//cout<<"Index "<<i<<" with remaining weight "<<w<<" and value "<<input[i].value<<endl;

	if(mw[i][w]!=0)
		return mw[i][w];

	if(input[i].weight>w)
		return knapsack(input,w,i-1,mw);

	else
		return mw[i][w]=std::max(input[i].value+knapsack(input,w-input[i].weight,i-1,mw),knapsack(input,w,i-1,mw));

}

int main(){

	ui maxWeight;

	scanf("%d\n",&maxWeight);

	//cout<<maxWeight<<endl;
	
	ui i, w, v;
	buttay b;
	vector<buttay> input;
	while(scanf("%d %d %d\n",&i,&v,&w)!=EOF){
	
		b.index=i;
		b.value=v;
		b.weight=w;

		//cout<<b.index<<" "<<b.value<<" "<<b.weight<<endl;

		input.push_back(b);
	}

	vector< vector<int> > mw(input.size(),vector<int>(maxWeight+1,0));

	printf("Max value: %d\n",knapsack(input,maxWeight,input.size()-1,mw));

	return 0;
}
