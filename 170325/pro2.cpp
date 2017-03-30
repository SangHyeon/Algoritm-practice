#include<iostream>
using namespace std;

int arr[1000000];
int cache[1000000];
int main() {
    int size;
    cin>>size;
    
    for(int i=0; i<size; i++)
        cin>>arr[i];

    int temp = arr[0];

    cache[0] = temp;
    int max = temp;
    for(int i=1; i<size; i++) {
        if(cache[i-1] < 0) {
            cache[i] = arr[i];
        } else {
            cache[i] = arr[i] + cache[i-1];
        }
    }

    for(int i=0; i<size; i++)
        cout<<cache[i]<<" ";
    cout<<endl;

    for(int i=1; i<size; i++) {
        if(max < cache[i])
            max = cache[i];
    }
    cout<<max<<endl;
    return 0;
}
