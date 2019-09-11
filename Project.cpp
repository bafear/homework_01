#include<iostream>
#include<string>
using namespace std;
int login();
void Add_book();
void borrow();
void Return_book();
void Report();
int main()
{
	int r=1;
	char choose;
	string student_first[20], student_last[20], branch[20], faculty[20], Student_ID[20];
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
		{
			char chose;
			int i=1;
			cout<<"--------------Register--------------\n";
			do
			{
				cout<<"Input you first name : ";
				cin >>student_first[r-1];
				cout<<"Input you last name : ";
				cin >>student_last[r-1];
				cout<<"Input you Student ID : ";
				cin >>Student_ID[r-1];
				cout<<"Input you faculty : ";
				cin >>faculty[r-1];
				cout<<"Input you branch : ";
				cin >>branch[r-1];

				cout<<"Please check for accuracy.\n"
					<<"Name : "<<student_first[r-1]<<" "<<student_last[i-1]<<endl
					<<"Student ID : "<<Student_ID[r-1]<<endl
					<<"Faculty : "<<faculty[r-1]<<endl
					<<"Branch : "<<branch[r-1]<<endl
					<<"Press Y(YES) or N(NO) or Press anykey for cancel: ";
				cin >>chose;
				if (chose == 'Y' || chose == 'y')
				{
					cout<<"\nRegister complate\n";
					i=0;
					r++;
				}
				else if (chose == 'N' || chose == 'n')
					i=1;
				else
				{
					cout<<"\ncancel.\n";
					break;
				}
			}while(i == 1);
		}
		else if (choose == '2')
			Add_book();
		else if (choose == '3')
			borrow();
		else if (choose == '4')
			Return_book();
		else if (choose == '5')
		{
			string log;
			cout<<"Plest input your student ID: ";
			cin >>log;
			int i = login(r-1,Student_ID,log);
		}
	}while(choose == '1' || choose == '2'|| choose == '3' || choose == '4' || choose == '5');
	return 0;
}

int login(int r,string Student_ID[],string login)
{
	int i;
	for(i=0;i<r;i++)
	{
		if(login == Student_ID[i])
		{
			break;
		}
	}
	return i;
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
