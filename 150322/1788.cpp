#include<iostream>
using namespace std;

unsigned int cache[1000000] = {0, };
unsigned long long int fibo(int n) {
    for(int i=3; i<=n; i++)
        cache[i] = (cache[i-1] + cache[i-2])%1000000000;
    return cache[n];
}

int main() {
    int n;
    int flag;
    unsigned long long int result;
    cin>>n;
    if(n == 0)
        cout<<0<<endl<<0<<endl;
    else {
        cache[0] = 0;
        cache[1] = 1;
        cache[2] = 1;
        if(n > 0)
            flag = 1;
        else
            flag = -1;

        result = fibo(n*flag);
        if(flag == -1) 
            if(n%2 != 0)
                flag = 1;

        cout<<flag<<endl<<result<<endl;
    }

    return 0;
}
