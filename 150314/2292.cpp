#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int interval = 1;
    int find = 1;
    int cnt = 1;
    while(1) {
        if(find >= n)
            break;
        find += (interval*6);
        cnt++;
        interval++;
    }

    cout<<cnt<<endl;

    return 0;
}
