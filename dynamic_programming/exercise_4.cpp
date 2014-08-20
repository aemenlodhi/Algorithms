#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct month{

	int n=0;
	int s=0;
	char city='n';

};

int opt(const vector<month>& d, const int& M, const int& i, const char& c, vector< vector<int> >& memo){

	if(i<0)
		return 0;

	else{
	
		if(c=='n' && memo[0][i]!=0)
			return memo[0][i];

		else if(c=='s' && memo[1][i]!=0)
			return memo[1][i];

	

		else{
	
			if(c=='n'){
				return memo[0][i]=min(d[i].n+opt(d,M,i-1,'n',memo),d[i].n+M+opt(d,M,i-1,'s',memo));	
			}

			else{
				return memo[1][i]=min(d[i].s+opt(d,M,i-1,'s',memo),d[i].s+M+opt(d,M,i-1,'n',memo));	
	
			}
	
		}

	}
		
}

int main(){

	int nMonths=0;
	scanf("%d\n",&nMonths);
	printf("Num months: %d\n",nMonths);
	
	month m;	
	vector<month> datum;

	int M;
	scanf("%d\n",&M);

	vector< vector<int> > memo(2,vector<int>(nMonths,0));

	while(nMonths--){
	
		scanf("%d %d",&m.n,&m.s);
		datum.push_back(m);
		
	}	


	printf("Min cost: %d\n",min(opt(datum,M,datum.size()-1,'n',memo),opt(datum,M,datum.size()-1,'s',memo)));
	return 0;
}
