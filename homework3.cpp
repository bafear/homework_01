#include<iostream>
using namespace std;
int main()
{
	float s, st;
	cout<<"Enter your score : ";
	cin	>>s;
		//line9-10 check int
	st = static_cast<int>(s);
	if(st == s)
		{
			//check int--> (0-100)
			if(0 <= s <= 100)
			{
				cout<<"Your GRADE : ";
				if (s < 60)
					cout<<"F";
				else if (s < 70)
					cout<<"D";
				else if (s < 80)
					cout<<"C";
				else if (s < 90)
					cout<<"B";
				else
					cout<<"A";
			}
			else
			{cout<<"Eror.";}
		}
	else
		{
			cout<<"Eror plese input integer.";
		}
	cout<<endl;
	return 0;
}