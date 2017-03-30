#include<iostream>
using namespace std;

int main() {
    int t, result;
    int t1 = 1;
    int cnt  = 1;
    cin>>t;
    
    while(1) {
        if(t == 1) {
            result = 1; 
            break;
        }

        if(t1 >= t) {
            result = cnt; 
            break;
        }
        t1 += 6*cnt;
        cnt++;
    }

    cout<<result<<endl;
    return 0;
}
