#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){

	srand(time(NULL));
	fstream f;
	f.open("input.txt",ios::out);
	unsigned int value, numCoins;
	unsigned int MAX_VALUE=1000;
	unsigned int MAX_COIN=50;
	
	value=rand()%MAX_VALUE;
	numCoins=20;

	f<<value<<endl<<numCoins<<endl<<"1"<<endl;
	int prev=1;	
	for(int i=2;i<=numCoins;i++){
		prev+=(rand()%4+1);
		f<<prev<<endl;
	}

	f.close();

	return 0;
}
