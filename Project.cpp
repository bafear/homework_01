#include<iostream>
#include<string>
using namespace std;
void Register();
void Add_book();
void borrow();
void Return_book();
void Report();
int main()
{
	char choose;
	do
	{
		cout<<"////////////////Menu////////////////\n"
				<<" 1. Register\n"
				<<" 2. Add book infor\n"
				<<" 3. Borrow a book\n"
				<<" 4. Return the book\n"
				<<" 5. Report\n"
				<<"____________________________\n"
				<<"Enter Menu : ";
		cin >>choose;
		if (choose == '1')
			Register();
		else if (choose == '2')
			Add_book();
		else if (choose == '3')
			borrow();
		else if (choose == '4')
			Return_book();
		else if (choose == '5')
			Report();
	}while(choose == '1' || choose == '2'|| choose == '3' || choose == '4' || choose == '5');
	return 0;
}

void Register()
{

}

void Add_book()
{

}

void borrow()
{

}

void Return_book()
{

}

void Report()
{

}