

int multrow(int a, int b ){
	for(int j=0;j<n;j++){
		int sum=sum + arr3[a][j]*arr2[b][j];
		return sum ;
	}
}
void disp(){
	for (int i=0;i<n;i++){
		for(int j=0;j<0;j++){
		cout<<arr1[i][j];
		}
	cout<<endl;
	}
}



int main(){
	disp();
	for(int a=0;a<m;a++){
		for(int b=0;b<n;b++){
			arr3[a][b]=multrow(a,b);
		}
	}
	
	disp();
}
