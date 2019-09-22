#include<iostream>
#include<string>
using namespace std;
int login(int r,string Student_ID[],string login);
void borrow();
void Return_book();
void Report();
int main()
{
	int r=0,numbook = 0,stock_book[20];
	char chose, check;
	string student_first[20], student_last[20], branch[20], faculty[20], Student_ID[20],ID_book[20],Name_book[20];
	do
	{
		string log;
		cout<<"////////////////Menu////////////////\n"
				<<" 1. Register\n"
				<<" 2. Add book infor\n"
				<<" 3. Borrow a book\n"
				<<" 4. Return the book\n"
				<<" 5. Report\n"
				<<"____________________________\n"
				<<"Enter Menu : ";
		cin >>chose;
		if (chose == '1')
		{
			int i=1;
			cout<<"--------------Register--------------\n";
			do
			{
				cout<<"Input you first name : ";
				cin >>student_first[r];
				cout<<"Input you last name : ";
				cin >>student_last[r];
				cout<<"Input you Student ID : ";
				cin >>Student_ID[r];
				cout<<"Input you faculty : ";
				cin >>faculty[r];
				cout<<"Input you branch : ";
				cin >>branch[r];

				cout<<"Please check for accuracy.\n"
					<<"Name : "<<student_first[r]<<" "<<student_last[r]<<endl
					<<"Student ID : "<<Student_ID[r]<<endl
					<<"Faculty : "<<faculty[r]<<endl
					<<"Branch : "<<branch[r]<<endl
					<<"Press Y(YES) or N(NO) or Press anykey for cancel: ";
				cin >>check;
				if (check == 'Y' || check == 'y')
				{
					cout<<"\nRegister complate\n";
					i=0;
					r++;
				}
				else if (check == 'N' || check == 'n')
					i=1;
				else
				{
					cout<<"\ncancel.\n";
					break;
				}
			}while(i == 1);
		}
/////////////////////////////////////////////
		else if (chose == '2')
		{
			int i=1;
			char choose;
			cout<<"Do you want to add new books or increase the number of existing books?\n"
				<<"1 Add new books.\n"
				<<"2 Increase the number of books.\n"
				<<"Press 1 or 2 or Press anykey for cancel: ";
			cin >>choose;
			if (choose == '1')
			{
				do
				{
					cout<<"\nAdd new books\n"
						<<"~~~~~~~~~~~~~~~~~~~~\n"
						<<"Enter the book name : ";
					cin >>Name_book[numbook];
					cout<<"Enter the number of books : ";
					cin >>stock_book[numbook];
					cout<<"Create book ID : ";
					cin >>ID_book[numbook];
					cout<<"Please check for accuracy.\n"
						<<"Press Y(YES) or N(NO) or Press anykey for cancel: ";
					cin >>check;
					if (check == 'Y' || check == 'y')
					{
						cout<<"Add new book Complate.\n";
						numbook++;
						i = 0;
					}
					else if (check == 'N' || check == 'n')
						i = 1;
					else
					{
						cout<<"\ncancel.\n";
						break;
					}
				}while(i == 1);
			}
			else if (choose == '2')
			{
				int i , t=1;
				string check_ID;
				do
				{
					cout<<"Input book ID : ";
					cin >>check_ID;
					for(i=0;i<r;i++)
					{
						if(check_ID == ID_book[i])
						{
							break;
						}
					}
					cout<<"\""<<Name_book[i]<<"\""<<" Is this book?\n";
					cout<<"Press Y(YES) or N(NO) or Press anykey for cancel: ";
					cin >>check;
					if(check == 'Y' || check == 'y')
					{
						int add;
						cout<<"How many books are added? : ";
						cin >>add;
						stock_book[i] += add;
						t=0;
					}
					else if(check == 'N' || check == 'n')
					{
						t=1;
					}
					else
					break;
				}while(t == 1);
			}
			else
				cout<<"\ncancel.\n";
		}
/////////////////////////////////////////////
		else if (chose == '3')
		{
			cout<<"Plest input your student ID: ";
			cin >>log;
			int i = login(r,Student_ID,log);
			cout<<"Hello "<<student_first[i]<<" "<<student_last[i]<<"\n\n";
			borrow();
		}
/////////////////////////////////////////////
		else if (chose == '4')
		{
			cout<<"Plest input your student ID: ";
			cin >>log;
			int i = login(r,Student_ID,log);
			cout<<"Hello "<<student_first[i]<<" "<<student_last[i]<<"\n\n";
			Return_book();
		}
/////////////////////////////////////////////
		else if (chose == '5')
		{
			cout<<"Plest input your student ID: ";
			cin >>log;
			int i = login(r,Student_ID,log);
			cout<<"Hello "<<student_first[i]<<" "<<student_last[i]<<"\n\n";
		}
	}while(chose == '1' || chose == '2'|| chose == '3' || chose == '4' || chose == '5');
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

void borrow()
{

}

void Return_book()
{

}

void Report()
{

}
