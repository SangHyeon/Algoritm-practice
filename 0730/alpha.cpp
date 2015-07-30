#include<iostream>
using namespace std;
int size;
char data[11];
void alpha(int n) {
    int i, j;
    char temp;
    if(n==0) {
        for(j=size; j>=0; j--)
            cout<<data[j];
        cout<<endl;
        return;
    }
    for(i = 0; i<n; i++) {
        temp = data[i];
        for(j=i+1; j<n; j++) {
            data[j-1] = data[j];
        }
        data[n-1] = temp;

        alpha(n-1);

        for(j=n-1; j>i; j--)
            data[j] = data[j-1];
        data[i] = temp;
        if(data[i] == data[i+1])
            i++;
    }
    return;
}

int main() {
    cin>>size;
    cin>>data;
    alpha(size);

    return 0;
}
