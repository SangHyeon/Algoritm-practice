#include<iostream>
using namespace std;

void merge(int *arr,int start,int mid,int end, int *arr_buf){
   int i0 = start,i1 = mid+1;
   for(int i = start; i<= end; i++){
      if( i0 <= mid && ( i1 > end || arr[i0] < arr[i1] ))
         arr_buf[i] = arr[i0++];
      else
         arr_buf[i] = arr[i1++];
   }
}

void merge_sort(int *arr,int start, int end, int *arr_buf){
   if(start == end) return;
   int mid = (start + end) / 2;
    
   merge_sort(arr,start,mid,arr_buf);
   merge_sort(arr,mid+1,end,arr_buf);
   merge(arr,start,mid,end,arr_buf);

   for(int i =start; i <= end; i++)
      arr[i] = arr_buf[i];
}

int main() {
    int arr[10] = { 6, 2 , 53, 3, 5, 12, 1, 4, 33, 9};
    int buf[10] = {0};
    merge_sort(arr, 0, 9, buf);

    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;


    return 0;
}
