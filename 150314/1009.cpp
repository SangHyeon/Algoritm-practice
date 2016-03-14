#include<iostream>
using namespace std;

int main() {
    int CaseNum;
    cin>>CaseNum;
    for(int k=0;k<CaseNum;k++) {
        int a, b, t;
        cin>>a>>b;
        t = a;

        if( a == 1 ) {
            cout<<1<<endl;
            continue;
        }

        for(int i=1; i<b; i++) {
            a *= t;
            a %= 10;
        }

        if(a == 0)
            cout<<10<<endl;
        else
            cout<<a<<endl;
    }

    return 0;
}
