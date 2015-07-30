#include<iostream>
using namespace std;

long long cache[100] = {0};

long long pinary_num(long long n) {
    if(n == 1 || n == 2)
        return 1;
    if(cache[n] != 0)
        return cache[n];

    return cache[n] = pinary_num(n-1) + pinary_num(n-2);
}

int main() {
    long long n;
    cin>>n;

    cout<<pinary_num(n)<<endl;

    return 0;
}
