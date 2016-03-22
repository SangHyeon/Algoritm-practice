#include<iostream>
using namespace std;

int main() { 
    int n, a, b;
    cin>>n>>a>>b;

    if(a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int cnt = 1;
    while(1) {
        if(a%2 == 1 && a+1 == b)
            break;
        else{
            if(a%2 == 1)
                a++;
            if(b%2 == 1)
                b++;
            a /= 2;
            b /= 2;
            if(a == 0)
                a++;
        }
        cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}
