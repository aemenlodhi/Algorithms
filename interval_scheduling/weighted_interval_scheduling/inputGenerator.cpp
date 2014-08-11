#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){

	srand(time(NULL));
	fstream f;
	f.open("input.txt",ios::out);
	unsigned int value, startTime, endTime;
	unsigned int MAX_VALUE=100;

	for(int i=0;i<100;i++){
		
		value=rand()%MAX_VALUE;
		startTime=rand()%100;
		endTime=startTime+rand()%100;

		f<<i<<" "<<value<<" "<<startTime<<" "<<endTime<<endl;

	}

	f.close();

	return 0;
}
