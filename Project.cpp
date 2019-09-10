#include<iostream>
#include<string>
using namespace std;
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
		{
			int i=1,r = 1 ; //i for end loop
			char chose;
			string *student_first = new string[r];
			string *student_last = new string[r];
			string *branch = new string[r];
			string *faculty = new string[r];
			string *Student_ID = new string[r];
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
			Report();
	}while(choose == '1' || choose == '2'|| choose == '3' || choose == '4' || choose == '5');
	return 0;
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
