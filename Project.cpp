#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int login(int r,string Student_ID[]);
int check_book(int numbook,string check_ID,string ID_book[]);
void return_book(int numbook ,string ID_book[] ,string borrow,int stock_book[],int &borrow_num);
void memu_main()
{
cout<<"////////////////Menu////////////////\n"
	<<" 1. Register\n"
	<<" 2. Add book infor\n"
	<<" 3. Borrow a book\n"
	<<" 4. Return the book\n"
	<<" 5. Report\n"
	<<"____________________________\n"
	<<"Enter Menu : ";
}

void menu_addbook()
{
cout<<"Do you want to add new books or increase the number of existing books?\n"
	<<"1 Add new books.\n"
	<<"2 Increase the number of books.\n"
	<<"Press 1 or 2 or Press anykey for cancel: ";
}
int main()
{
	int std=1,numbook = 2,stock_book[20],borrow_num[20];
	char chose, check;
	string student_first[20], student_last[20], branch[20], faculty[20], Student_ID[20];
	string ID_book[20],Name_book[20],ID_book_borrow1[20],ID_book_borrow2[20],ID_book_borrow3[20];
	//////student 1
	student_first[0] = "Supavarit",student_last[0]="Lexnopparat",branch[0]="IT",faculty[0]="IT",Student_ID[0]="6206021612113",
		borrow_num[0]=0,ID_book_borrow1[0]="empty",ID_book_borrow2[0]="empty",ID_book_borrow3[0]="empty";
	//////Book
	Name_book[0]="Herry_potter_1",ID_book[0]="0001", stock_book[0]=5,
	Name_book[1]="Herry_potter_2",ID_book[1]="0002", stock_book[1]=1;
	do
	{
		string log;
		memu_main();
		cin >>chose;
		if (chose == '1')
		{
			int t=1;
			cout<<"--------------Register--------------\n";
			do
			{
				string first = "",last = "",SID ="", Faculty = "", Branch = "";
				cout<<"Input you first name : ";
				cin >>first;
				cout<<"Input you last name : ";
				cin >>last;
				cout<<"Input you Student ID : ";
				cin >>SID;
				cout<<"Input you faculty : ";
				cin >>Faculty;
				cout<<"Input you branch : ";
				cin >>Branch;

				cout<<"Please check for accuracy.\n"
					<<"Name : "<<first<<" "<<last<<endl
					<<"Student ID : "<<SID<<endl
					<<"Faculty : "<<Faculty<<endl
					<<"Branch : "<<Branch<<endl
					<<"Press Y(YES) or N(NO) or Press anykey for cancel: ";
				cin >>check;
				if (check == 'Y' || check == 'y')
				{
					student_first[std]=first;
					student_last[std]=last;
					Student_ID[std]=SID;
					faculty[std]=Faculty;
					branch[std]=Branch;
					borrow_num[std]=0;
					ID_book_borrow1[std]="empty";
					ID_book_borrow2[std]="empty";
					ID_book_borrow3[std]="empty";
					cout<<"\nRegister complate\n";
					t=0;
					std++;
				}
				else if (check == 'N' || check == 'n')
					t=1;
				else
				{
					cout<<"\ncancel.\n";
					break;
				}
			}while(t == 1);
		}
/////////////////////////////////////////////
		else if (chose == '2')
		{
			int t=1;
			char choose;
			menu_addbook();
			cin >>choose;
			if (choose == '1')
			{
				do
				{
					string name="",IDBook="";
					int stock = 0;
					cout<<"\nAdd new books\n"
						<<"~~~~~~~~~~~~~~~~~~~~\n"
						<<"Enter the book name : ";
					cin >>name;
					cout<<"Enter the number of books : ";
					cin >>stock;
					cout<<"Create book ID : ";
					cin >>IDBook;
					cout<<"Please check for accuracy.\n"
						<<"Press Y(YES) or N(NO) or Press anykey for cancel: ";
					cin >>check;
					if (check == 'Y' || check == 'y')
					{
						Name_book[numbook]=name;
						stock_book[numbook]=stock;
						ID_book[numbook]=IDBook;
						cout<<"Add new book Complate.\n";
						numbook++;
						t = 0;
					}
					else if (check == 'N' || check == 'n')
						t = 1;
					else
					{
						cout<<"\ncancel.\n";
						break;
					}
				}while(t == 1);
			}
			else if (choose == '2')
			{
				int t=1;
				string check_ID;
				do
				{
					int i;
					cout<<"Input book ID : ";
					cin >>check_ID;
					for(i=0;i<numbook;i++)
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
						cout<<"Add Book Compleat\n";
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
			int Student = login(std,Student_ID);
			
			int t=1;
			do
			{
				if (Student== -1)break;
				if (borrow_num[Student]==3)
				{
					cout<<"You have reached the quota amount. Please return the book before borrowing it again.\n";
					break;
				}
				string check_ID;
				cout<<"Plese input book ID: ";
				cin >>check_ID;
				int i = check_book(numbook,check_ID,ID_book);
				if (i==numbook)
				{
					cout<<"The library does not have a book, code "<<check_ID<<endl;
					break;
				}

				cout<<"\""<<Name_book[i]<<"\""<<" Is this book?\n";
				cout<<"Press Y(YES) or N(NO) or Press anykey for cancel: ";
				cin >>check;
				if (check == 'Y' || check == 'y')
				{
					stock_book[i]--;
					borrow_num[Student]++;
					if (ID_book_borrow1[Student]=="empty") ID_book_borrow1[Student] = ID_book[i];
					else if (ID_book_borrow2[Student]=="empty") ID_book_borrow2[Student] = ID_book[i];
					else if (ID_book_borrow3[Student]=="empty") ID_book_borrow3[Student] = ID_book[i];
					if (borrow_num[Student]==3)
					{
						cout<<"You have reached the quota amount.\n";
						break;
					}
					cout<<"Do you want to borrow more books?";
					cout<<"\nPress Y(YES) or N(NO) : ";
					cin >>check;
					if (check == 'Y' || check == 'y') 
						{
							cout<<endl;
							t = 1;
						}
					else t=0;
				}
				else if (check == 'N' || check == 'n') t = 1;
				else
				{
					cout<<"\ncancel.\n";
					break;
				}
			}while(t == 1);
		}
/////////////////////////////////////////////
		else if (chose == '4')
		{
			int Student = login(std,Student_ID);
			int t = 1;
			do
			{
			if (Student == -1) break;

			if (borrow_num[Student]==0)
			{
				cout<<"You don't have any books to borrow.\n\n";
				break;
			}
			cout<<"-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-\n"
				<<" No.            Name Book\n"
				<<"-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-\n";
			cout<<setw(4)<<"1"<<setw(25)<<Name_book[check_book(numbook,ID_book_borrow1[Student],ID_book)]<<endl;
			cout<<setw(4)<<"2"<<setw(25)<<Name_book[check_book(numbook,ID_book_borrow2[Student],ID_book)]<<endl;
			cout<<setw(4)<<"3"<<setw(25)<<Name_book[check_book(numbook,ID_book_borrow3[Student],ID_book)]<<endl<<endl;
			cout<<"1. Return all books ("<< borrow_num[Student] <<" books)?\n";
			cout<<"2. Return 1 books\n";
			cout<<"Q. Exit\n";
			cout<<"Press 1, 2 and Q : ";
			cin >>check;
			if (check == '1') 
				{
					if (ID_book_borrow1[Student] != "empty")
					{
						return_book(numbook, ID_book, ID_book_borrow1[Student], stock_book,borrow_num[Student]);
						ID_book_borrow1[Student] = "empty";
					}
					if (ID_book_borrow2[Student] != "empty")
					{
						return_book(numbook, ID_book, ID_book_borrow2[Student], stock_book,borrow_num[Student]);
						ID_book_borrow2[Student] = "empty";
					}
					if (ID_book_borrow3[Student] != "empty")
					{
						return_book(numbook, ID_book, ID_book_borrow3[Student], stock_book,borrow_num[Student]);
						ID_book_borrow3[Student] = "empty";
					}
					cout<<"\nYou return all book.";
					t = 0;
				}
			else if(check == '2')
			{
				cout<<"Which book would you like to return?\n"
					<<"No. ";
				cin >>check;
				if (check == '1')
				{
					if (ID_book_borrow1[Student] != "empty")
					{
						return_book(numbook, ID_book, ID_book_borrow1[Student], stock_book,borrow_num[Student]);
						ID_book_borrow1[Student] = "empty";
						cout<<"Successfully returned\n";
					}
					else cout<<"\nNo. 1 Not borrowing books";
				}
				else if (check == '2')
				{
					if (ID_book_borrow1[Student] != "empty")
					{
						return_book(numbook, ID_book, ID_book_borrow1[Student], stock_book,borrow_num[Student]);
						ID_book_borrow1[Student] = "empty";
						cout<<"Successfully returned\n";
					}
					else cout<<"\nNo. 2 Not borrowing books";
				}
				else if (check == '3')
				{
					if (ID_book_borrow1[Student] != "empty")
					{
						return_book(numbook, ID_book, ID_book_borrow1[Student], stock_book,borrow_num[Student]);
						ID_book_borrow1[Student] = "empty";
						cout<<"Successfully returned\n";
					}
					else cout<<"\nNo. 3 Not borrowing books";
				}
				t=0;
			}
			}while(t == 1);
		}
/////////////////////////////////////////////
		else if (chose == '5')
		{
			int Student = login(std,Student_ID);
			int t = 1;
			do
			{
			if (Student == -1) break;
			}while(t == 1);
		}
	}while(chose == '1' || chose == '2'|| chose == '3' || chose == '4' || chose == '5');
	return 0;
}

int login(int r,string Student_ID[])
{
	string login;
	cout<<"Plest input your student ID: ";
	cin >>login;
	int i;
	for(i=0;i<r;i++)
	{
		if(login == Student_ID[i])
		{
			cout<<"hi\n";
			return i;
		}
	}
	cout<<"Plese register\n";
	return -1;
}

int check_book(int numbook,string check_ID,string ID_book[])
{
	int i;
	for(i=0;i<numbook;i++)
	{
		if(check_ID == ID_book[i])
		{
			return i;
		}
	}
	return i;
}

void return_book(int numbook ,string ID_book[] ,string borrow, int stock_book[],int &borrow_num)
{
	for(int q=0 ;q<numbook;q++)
		{
			if(ID_book[q]==borrow)
			{
				stock_book[q]++;
				borrow_num--;
				break;
			}
		}
}
