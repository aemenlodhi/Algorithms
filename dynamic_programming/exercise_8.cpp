#include<vector>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>

using namespace std;

int maxBot(const vector<int>& nB, const vector<int>& kB, int i){

	if(i<0)
		return 0;

	else{

		int m=0,temp=0;
		for(int j=0;j<i;j++){
			temp=min(nB[i],kB[i-j])+maxBot(nB,kB,j);
		
			cout<<"Fire at "<<i<<" and reboot at "<<j<<" kills "<<temp<<" bots"<<endl;
			
			if(temp>m)
				m=temp;
		}
			
		return m;	
	} 


}

int main(){

	int tTime=0;
	scanf("%d\n",&tTime);
	
	vector<int> nBots;
	vector<int> killBots;



	int temp1,temp2;
	while(tTime--){
	
		scanf("%d %d\n",&temp1,&temp2);
		nBots.push_back(temp1);
		killBots.push_back(temp2);

	}
	
	
	printf("Max bots are %d\n",maxBot(nBots,killBots,nBots.size()-1));
	

	return 0;

}
