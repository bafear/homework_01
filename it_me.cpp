#include<iostream>
#include<string>
using namespace std;
void ListStudent(string name[],int score[],int);
char Calgrade(int score);
int main()
{
	string name[15] ;
	int score[15] ,num_student;
	cout<<"Input Number of Student : ";
	cin >> num_student;
	for(int i=0;i<num_student;i++)
	{
		cout<<"Input Name : ";
		cin >>name[i];
		cout<<"Input Score : ";
		cin >>score[i];
		cout<<endl;
	}
	ListStudent(name,score,num_student);
	return 0;
}

void ListStudent(string name[],int score[],int num)
{
	for(int i=0; i<num ;i++)
		cout<<"Student Name:"<<name[i]<<" Score "<<i+1<<" = "<<score[i]<<"   Your grade is "<<Calgrade(score[i])<<endl;
}

char Calgrade(int score)
{
	if (score >=80)
		return 'A';
	else if (score >=70)
		return 'B';
	else if (score >=60)
		return 'C';
	else
		return 'D';
}