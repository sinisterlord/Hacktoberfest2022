#include <iostream>
using namespace std;


int main(){
	int at[10],bt[10],start[10],finish[10],tat[10],wt[10],i,n;
	char pn[10];
	int totwt,tottat;
	
	cout<<"enter number of processes";
	cin>>n;
	cout<<"enter process names,arrival time,burst time";
	for(int i=0;i<n;i++){
		cin>>pn[i]>>at[i]>>bt[i];
	}
	
	for(int i=0;i<n;i++){
		if(i==0){
			start[i]=at[i];
			finish[i]=at[i]+bt[i];
			tat[i]=finish[i]-at[i];
			wt[i]=start[i]-at[i];
			
		}
		
		else{
			if(at[i]<=finish[i-1]){
				start[i]=finish[i-1];
			}
			
			else{
				start[i]=at[i];
				
			}
			
			finish[i]=start[i]+bt[i];
			tat[i]=finish[i]-at[i];
			wt[i]=start[i]-at[i];		
			
		}
	}
	
	
	cout<<"\nName at bt start tat finish";
		for(i=0;i<n;i++)
			{
				cout<<pn[i]<<at[i]<<bt[i]<<start[i]<<tat[i]<<finish[i];
				totwt+=wt[i];
				tottat+=tat[i];
			}
			
		cout<<"avg wt="<<totwt/n;
		cout<<"avg tat"<<tottat/n;


}
