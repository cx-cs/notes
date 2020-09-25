#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	srand((unsigned)time(NULL));
	for(int i=0;i<10;i++)
		printf("%d ",(int)(1.0*rand()/RAND_MAX*400+100));//[100,500]
	system("pause");
}