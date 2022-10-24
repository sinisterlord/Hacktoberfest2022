import java.util.Arrays;

class QuickSort{

    //method to swap values
    static void swap(int arr[], int actualPosOfPivot, int s){
        int temp = arr[actualPosOfPivot];
        arr[actualPosOfPivot]= arr[s];
        arr[s]= temp;
    }
    static int partition(int arr[], int s , int e){
        //first take start a pivot
        int pivot = arr[s];
        //now count how many elements are smaller than pivot in the array
        //to find actual position of the pivot in the array
        int count =0;
         for(int i = s+1;i<=e;i++){
            if(arr[i]<pivot)
              count++;
         }
         //now evaluating the actual position of the pivot
         int actualPosOfPivot = s+count;
         //now swap the  number to its actual position
         swap(arr, actualPosOfPivot,s);

         //now the left side elements of pivot should be smaller than pivot and right side elements should be 
         //larger than pivot
         int i = s;
         int j = e;

         while(i<actualPosOfPivot && j>actualPosOfPivot){
            //if all element is already smnaller than pivot
            while(arr[i]>pivot){
                i++;
            }

            //if all element is already larger than pivot
            while(arr[j]<=pivot){
                j--;
            }

            //if still some elements then swap those elements 
            if( i<actualPosOfPivot && j>actualPosOfPivot){
                    swap(arr,i,j);
            }

         }
         return actualPosOfPivot;
    }

     static void quickSort(int arr[],int s , int e){
        //base condition
        if(s>=e)
          return;
        int p = partition(arr,s,e);
        //now sort left side of the pivot
        quickSort(arr, s, p-1);
        //now sort right side of the pivot
        quickSort(arr,p+1,e);
     }

    public static void main(String[] args) {
        int arr[] ={34,212,12,-1,67,0};
        System.out.println("Before sorting :- "+Arrays.toString(arr));
        
        quickSort(arr,0,arr.length-1);
        System.out.println("After sorting :- "+Arrays.toString(arr));
    }
}