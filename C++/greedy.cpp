#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct job{
	int profit, deadline;
char id;
};

bool comp(job a1,job a2){
	return(a1.deadline<a2.deadline);
}

void select(Activity arr[],int n){
	
	sort(arr, arr+n, comp);

	
	for(inti=1;i<n;i++){
		
			for(int j=min(n,arr[i].deadline)-1;j>n;j--){
		
		if(slot[j]==false){
			result[j]=i;
			slot[j]=true;
			break;
		}
}

		
}

int main()
{
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    select(arr, n);
    return 0;
}
