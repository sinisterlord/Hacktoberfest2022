#include<iostream>
using namespace std;
// recursive function
int fact(int n){
    if(n==1||n==0)
    return 1;
    int ans;
    ans = n*fact(n-1);
}
int main()
{
    int n;
    cout<<"\n enter the number: ";
    cin>>n;
    cout<<fact(n)<<endl<<endl;
return 0;
}
