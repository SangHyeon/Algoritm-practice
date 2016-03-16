#include<iostream>
using namespace std;

int val[1000001] = {0,};
int num[3001] = {0,};

int main() {
    int n, tmp;
    int max_ = 0;
    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>tmp;
        num[i] = tmp;
        val[tmp] = 1;
    }

    int max_inc = (num[n-1] - num[0])/2 + 1;

    for(int i=0; i<n; i++) {
        int inc = 1;
        while(inc < max_inc) {
            int temp = num[i];
            int ttt = num[i];
            int cnt = 1;
            while(1) {
                if(temp+inc > 1000000)
                    break;
                if(val[temp+inc] == 1) {
                    cnt++;
                    temp += inc;
                    ttt += temp;
                }
                else
                    break;
            }
            if(cnt >= 3 && max_ < ttt)
                max_ = ttt;
            inc++;
        }
    }

    cout<<max_<<endl;

    return 0;
}
