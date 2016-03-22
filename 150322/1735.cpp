#include<iostream>
using namespace std;

long long int gcd(long long int a, long long int b) {
    return b ? gcd(b, a%b) : a; 
}

int main() {
    long long int a,b,c,d;
    cin>>a>>b>>c>>d;

    long long int lcm = (b*d)/gcd(b, d);
    long long int t1, t2;
    t1 = lcm/b;
    t2 = lcm/d;

    int ta, tb;
    ta = t1*a + t2*c;
    tb = lcm;

    while(1) {
        int temp = gcd(ta, tb);
        if(temp == 1)
            break;
        ta /= temp;
        tb /= temp;
    }

    cout<<ta<<" "<<tb<<endl;

    return 0;
}
