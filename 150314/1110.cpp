#include<iostream>
using namespace std;

int main() {
    int num;
    cin>>num;

    int val[2], result[2];
    result[0] = val[0] = num/10;
    result[1] = val[1] = num%10;
    
    int cnt = 0;

    while(1) {
        int temp[2];
        temp[0] = val[1];
        temp[1] = (val[0] + val[1])%10;
        val[0] = temp[0];
        val[1] = temp[1];
        cnt++;
        if(val[0] == result[0] && val[1] == result[1])
            break;
    }

    cout<<cnt<<endl;

    return 0;
}
