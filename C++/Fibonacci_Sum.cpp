#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  int fib[n];
  fib[0] = 1;
  fib[1] = 1;
  int sum = 2;
  for(int i=2;i<n;++i) {
    fib[n] = fib[n-1] + fib[n-2];
    sum+=fib[n];
  }
  cout<<sum<<"\n";
  return 0;
}
  
