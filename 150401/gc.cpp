#include <iostream>
using namespace std;
 
int main() {
    int arr[20] = { 1, 1, 2, };
    int n;
 
    for (int i=3;i<20;i++) {
        arr[i] = 0;
        for (int j=0;j<i;j++)
            arr[i] += arr[i-j-1]*arr[j];
    }
    cin>>n;
    cout<<arr[n]<<endl;
 
    return 0;
}
