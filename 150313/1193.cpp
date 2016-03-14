#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int i,j;
    int num = 1;
    while(1) {
        if (n-num <= 0) {
            if (num%2 == 1) {
                i = num-n+1;
                j = n;
            } 
            else {
                i = n;
                j = num-n+1;
            }
            break;
        }
        n -= num;
        num++;
    }
    cout<<i<<"/"<<j <<endl;
    return 0;
}
