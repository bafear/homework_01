#include <iostream>
#include <string>
using namespace std;
int main()
{
	string name = "Supavarit Lexnopparat";
	int score1 = 83, score2 = 81;
	char Grade = 'A';
	float GPA = 3.39;
	cout<<"My name is : " <<name <<endl
		<<"My scores 1 : " <<score1 <<" points\n"
		<<"My scores 2 : " <<score2 <<" points\n"
		<<"Total : " << score1+score2 <<endl
		<<"Grade : "<<Grade <<endl
		<<"GPA : "<<GPA <<endl;
return (0);
}