#include<iostream>
using namespace std;
int main()
{
	int num[3][2];
	for(int i=0;i<2;i++)
	{
		for(int r=0;r<3;r++)
		{
			cout<<"Input "<<i+1<<r+1<<":";
			cin >>num[r][i];
		}
	}

	cout<<"****************Display Array****************\n";
	for(int i=0;i<2;i++)
	{
		for(int r=0;r<3;r++)
		{
			cout<<num[r][i]<<"\t";
		}
		cout<<endl;
	}
	cout<<"***************Transpose Array***************\n";
	for(int r=0;r<3;r++)
	{
		for(int i=0;i<2;i++)
		{
			cout<<num[r][i]<<"\t";
		}
		cout<<endl;
	}
}