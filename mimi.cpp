#include<iostream>
#include<iomanip>
using namespace std;
void checkNum(int,int);
int main()
{
	srand(time(NULL));
	int rd,num,r = 0;
	cout<<"###Welcome to guessing number game###\n"
		<<"Secret number hes been chosen\n";
	rd = rand()%10+1;
	do
	{
		cout<<"Guess the number(1 to 10): ";
		cin >>num;
		checkNum(num,rd);
		r++;
	}while(num != rd);
	cout<<"\nThe secret number is "<<rd
		<<"\nYou made "<< r <<" guesses\n";
	return 0;
}

void checkNum(int num,int rd)
{
	if(num < rd)
	{
		cout<<"This secret number is lower";
	}
	else if(num > rd)
	{
		cout<<"This secret number is higher";
	}
	else
	{
		cout<<"Congratulation!";
	}
}