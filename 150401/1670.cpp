#include <iostream>
using namespace std;
 
int main() {
    long long int arr[5001] = { 1, 1, 2, };
    int n;
 
    for (int i=3;i<5001;i++) {
        arr[i] = 0;
        for (int j=0;j<i;j++) {
            arr[i] += (arr[i-j-1]*arr[j])%987654321;
            arr[i] %= 987654321;
        }
    }
    cin>>n;
    cout<<arr[n/2]<<endl;
    return 0;
}
