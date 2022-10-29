#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the no ";
	cin>>n;
	int x = 01;
	if((n&x)==0)
	{
		cout<<"The number is even";
	}
	else 
	{
		cout<<"The number is odd";
	}
	return 0;
}
