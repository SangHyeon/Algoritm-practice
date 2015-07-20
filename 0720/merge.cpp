#include<iostream>
using namespace std;
#define SIZE 10
void merge_sort(int a[], int len);

int main() {
	int arr[10] = {34, 24, 13, 43, 23 ,54, 12, 76, 99, 33};

	cout<<"Before Merge Sort : ";
	for(int i=0; i<SIZE; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	merge_sort(arr, SIZE);

	cout<<"After Merge Sort : ";
	for(int i=0; i<SIZE; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}

void merge_sort(int a[], int len) {
	int first, second, varLen;
	int tmpArr[len];
	int i, j, k;

	for(int size = 1; size < len; size*=2) {
		first = -2 * size;
		second = first + size;
		while(second+size*2 < len) {
			first = second + size;
			second = first + size;
			i = first;
			j = second; 
			k = first;

			while(i<first + size || (j<second+size && j<len)) {
				if( a[i] <= a[j] ) {
					if( i < first+size)
						tmpArr[k++] = a[i++];
					else 
						tmpArr[k++] = a[j++];
				}
				else {
					if( j < second+size && j<len) {
						tmpArr[k++] = a[j++];
					}
					else {
						tmpArr[k++] = a[i++];
					}
				}
			}
		}
		for(i = 0; i<len; i++) {
			a[i] = tmpArr[i];
		}
	}
}
