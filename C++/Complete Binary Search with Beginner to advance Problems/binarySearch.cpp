#include<iostream>
using namespace std;
bool search(int arr[],int start,int end,int element){
    int mid = start + (end-start)/2;

    if(arr[mid]==element)
        return true;
    if(start==end)
        return 0;

    if(arr[mid]>element)
        return search(arr,start,mid-1,element);
    else
        return search(arr,mid+1,end,element);
}
int main()
{
    int even[6] = {2,4,6,8,12,18};
    int odd[5] = {3, 8, 11, 14, 16};

    if(search(even,0,6,0))
        cout<<"Found!"<<endl;
    else
        cout<<"Not Found!"<<endl;
        
return 0;
}

int findPeak(int arr[], int n) {

    int s =0, e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {
        //cout<<" s " << s <<" e " << e << endl;
        if(arr[mid] < arr[mid+1]){
            s = mid+1; 
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}
