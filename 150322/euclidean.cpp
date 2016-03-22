#include<iostream>
using namespace std;

int gcd(int a, int b)
{
        return b ? gcd(b, a%b) : a;
}

int main() {
    int a, b, gcd_;
    cin>>a>>b;
    
    gcd_ = gcd(a, b);
    cout<<gcd_<<" "<<(a*b)/gcd_<<endl;

    return 0;
}
