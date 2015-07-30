#include <stdio.h>

void swap(int arr[], int a, int b);
void place_num(int arr[], int start, int fin);

int main(void) {
    int n;
    int numArr[10];
    int i;

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        numArr[i] = i+1;
    }

    place_num(numArr, 0, n);

    return 0;
}

void swap(int arr[], int a, int b) {
    int tmp;
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void place_num(int arr[], int start, int fin) {
    int i, j;
    if (start == fin) {
        for(j=0; j<fin; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    } else {
        for (i=start; i<fin; i++) {
            swap(arr, start, i);
            place_num(arr, start+1, fin);
            swap(arr, start, i);
        }
    }
}
