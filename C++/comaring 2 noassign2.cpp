#include<iostream>
using namespace std;
int main()
{
	float a,b;
	cout<<"Enter the two numbers";
	cin>>a>>b;
	if(a>b)
	{
		cout<<"The first no is greater";
	}
	else if(b>a)
	{
		cout<<"The second no is greater ";
	}
	else 
	{
		cout<<"The no's are equal";
	}
	return 0;
}
