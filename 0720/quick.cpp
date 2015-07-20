#include<iostream>
using namespace std;
#define SIZE 10

void qsort(int a[], int len);
void swap(int a[], int indexX, int indexY); 

int main() {
	int arr[SIZE] = { 3, 13, 4, 6, 2, 9, 12, 1, 8, 7 };
	int i;
	for(int i=0; i<SIZE; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	qsort(arr, SIZE);

	for(int i=0; i<SIZE; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	return 0;
}

void qsort(int a[], int len) {
	int pVal;
	int pIndex = len-1;
	int i, j;
	
	if(len >1) {
		pVal = a[len-1];
		i = 0;
		j = len-2;

		while(1) {
			while(a[i] < pVal) i++;
			while(a[j] > pVal) j--;
			if(i >= j) break;
			swap(a, i, j);	
		}
		swap(a, i, pIndex);
		qsort(a, i);
		qsort(a+i+1, len-i-1);

	}

}

void swap(int a[], int indexX, int indexY) {
	int tmp;
	tmp = a[indexX];
	a[indexX] = a[indexY];
	a[indexY] = tmp;
}

