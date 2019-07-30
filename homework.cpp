#include<iostream>
#include<string>
using namespace std;
int main()
{
	string User, Pass, User_log, Pass_log;
	char choose;
	do
	{
		cout<<"////////////////Menu////////////////\n"
			<<" 1. Register\n"
			<<" 2. Login\n"
			<<" Q. Exit Program\n"
			<<"____________________________\n"
			<<"Enter Menu : ";
		cin >>choose;
		if(choose == '1')
		{
		cout<<"***********Register***********\n"
			<<"Input Username : ";
		cin >>User;
		cout<<"Input Password : ";
		cin >>Pass;
		}
		if(choose == '2')
		{
			do
			{
				cout<<"********Login********\n"
					<<"Input Username : ";
				cin >>User_log;
				cout<<"Input Password : ";
				cin >>Pass_log;
				if(!((User_log == User) && (Pass_log == Pass)))
					cout<<"Username or Password incorrect Please try again!!!! :(\n";
			}while(!((User_log == User) && (Pass_log == Pass)));
			cout<<"Username and Password correct ^__^\n";
		}
	}while ((choose != 'Q') && (choose != 'q'));
	cout<<"Exit Program....\n";
	return 0;
}
