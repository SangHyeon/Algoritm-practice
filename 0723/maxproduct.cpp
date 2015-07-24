#include<iostream>
using namespace std;

int main() {
    int num;
    double max;
    double t[10000];
    double r[10000];
    cin>>num;

    for(int i=0; i<num; i++)
        cin>>t[i];

    r[0] = t[0];
    for(int i=1; i<num; i++) {
        if(r[i-1] > 1) {
            r[i] = r[i-1]*t[i];
        }
        else
            r[i] = t[i];
    }
    max = r[0];
    for(int i=1; i<num; i++) {
        if(max < r[i])
            max = r[i];
    }

    printf("%.3lf\n", max);

    return 0;
}
