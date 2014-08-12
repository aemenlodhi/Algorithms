#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){

	srand(time(NULL));
	fstream f;
	f.open("input.txt",ios::out);
	unsigned int value, weight;
	unsigned int MAX_VALUE=1000;
	unsigned int MAX_WEIGHT=50;
	
	f<<MAX_WEIGHT<<endl;

	for(int i=0;i<10;i++){
		
		value=rand()%MAX_VALUE;
		weight=rand()%100;

		f<<i<<" "<<value<<" "<<weight<<endl;

	}

	f.close();

	return 0;
}
