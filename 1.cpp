#include<iostream>
using namespace std;
int main()
{
	float C;
	cout<< "Enter Cels temperature: ";
	cin	>> C;
	cout<<"Fahrenheit = " << ((C*9)/5)+32<< endl;
	cout<<"Now weather in Thailand is " << ((((C*9)/5)+32<70) ? "HOT" : "COOL") << endl;
	return 0;
}
