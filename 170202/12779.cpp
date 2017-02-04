#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

long long int gcd(long long int a, long long int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    long long int a,b;
    cin>>a>>b;
    
    long long int itv = b-a;

    long long int x = (long long int)sqrt(a);
    long long int y = (long long int)sqrt(b);

    if(y - x == 0)
        cout<<0<<endl;
    else {
        long long int g = gcd(y-x, itv);
        cout<<(y-x)/g<<"/"<<itv/g<<endl;
    }

    return 0;
}
