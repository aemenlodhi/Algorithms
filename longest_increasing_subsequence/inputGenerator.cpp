#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){

	int count=5000;
	fstream oFile;
	oFile.open("input.txt",ios::out);
	
	srand(time(NULL));
	for(int i=0;i<count;i++)
		oFile<<rand()%10000<<endl;

	oFile.close();

	return 0;
}
