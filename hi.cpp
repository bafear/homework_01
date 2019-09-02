#include<iostream>
#include<string>
using namespace std;
void update_balance(string command, float dollars, float &balance);
int main()
{
	string command;
	float balance = 10000 ,money;
	cout<<"Exit wiht 0\n";
	do
	{
		cout<<"Your balance = "<< balance << endl;
		cout<<"Input command 1 wihhdraw, 2 depost): ";
		cin>> command;
		if (command != "0")
		{
			cout<<"Input amount : ";
			cin >> money;
			update_balance(command,money,balance);
		}
	}while(command != "0");
	return 0;
}

void update_balance(string command, float dollars, float &balance)
{
	if (command == "1")
		balance = balance + dollars;
	else if (command == "2")
		balance = balance - dollars;
	else
		cout<< "Eror\n";
}