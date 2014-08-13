#include<vector>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<limits>

typedef int ui;

using namespace std;

struct product{

	ui value;
	ui weight;
	
};

struct person{

	ui weight;
	ui value;
	person();
};

person::person(){

	weight=value=0;

}

int multi_knapsack(vector<product> pv, vector<person> gv, int p, int g){


	if(p<0 || g<0)
		return 0;


	if(pv[p].weight > gv[g].weight){

		return std::max(multi_knapsack(pv,gv,p-1,g),multi_knapsack(pv,gv,p,g-1));
		
	}
	
	else{

		ui c2=std::max(multi_knapsack(pv,gv,p-1,g),multi_knapsack(pv,gv,p,g-1));
		gv[g].weight-=pv[p].weight;
		ui c1=pv[p].value+multi_knapsack(pv,gv,p-1,g);

		return std::max(c1,c2);

	}
	
}

int processCase(vector<product>& pv, vector<person>& gv){

	return multi_knapsack(pv,gv,pv.size()-1,gv.size()-1);

}

int main(){

	ui TC, numProducts,numG;
	product p;
	person g;
	vector<product> pv;
	vector<person> gv;

	scanf("%d\n",&TC);

	while(TC--){

		scanf("%d\n",&numProducts);

		pv.clear();
		gv.clear();
		
		for(ui i=0;i<numProducts;i++){
			scanf("%d %d\n",&p.value,&p.weight);
			pv.push_back(p);
		}

		scanf("%d\n",&numG);
		for(ui i=0;i<numG;i++){
			scanf("%d\n",&g.weight);
			gv.push_back(g);
		}

		printf("%d\n",processCase(pv,gv));
			
	}
	
	return 0;
}
