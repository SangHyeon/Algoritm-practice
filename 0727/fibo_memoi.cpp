#include<iostream>
using namespace std;
int cache[1000] ={0, };
int fibo(int n) {
    if(n == 1||n==2)
        return 1;
    if(cache[n] != 0)
        return cache[n];
    else {
        return cache[n] = fibo(n-1)+fibo(n-2);
    }
}

int main() {

    cout<<fibo(40)<<endl;

    return 0;
}
