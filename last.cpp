#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	int ran[30],t=0;
	for(int i=0;i<30;)
	{
		for(int j=0;j<6;j++)
		{
			ran[i] = rand()%10;
			cout<<ran[i]<<"\t";
			i++;
		}
		cout<<endl;
	}
	cout<<"--------------------display grapeh--------------------\n"
		<<"\t0\t1\t2\t3\t4\t5\n"
		<<"------------------------------------------------------\n";
	for(int i=0;i<30;)
	{
		cout<<t<<"|\t";
		for(int j=0;j<6;j++)
		{ 
			if(ran[i]!= 0)
				cout<<"*\t";
			else
				cout<<" \t";
			i++;
		}
		t++;
		cout<<endl;
	}
	return 0;
}