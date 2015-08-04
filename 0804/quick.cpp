#include <stdio.h>

void quickSort(int arr[], int low, int high)
{
   int i = low, j = high, t;
   int x = arr[(low + high) / 2];

   do
   {
      while (arr[i] < x) i++;
      while (arr[j] > x) j--;

      if (i <= j)
      {
         t = arr[i]; arr[i] = arr[j]; arr[j] = t;
         i++; j--;
      }
   } while (i <= j);

   if (low < j) quickSort(arr, low, j);
   if (i < high) quickSort(arr, i, high);
}

int main()
{
   int arr[4] = { 4, 3, 1, 2 };
   quickSort(arr, 0, 3);

   return 0;
}
