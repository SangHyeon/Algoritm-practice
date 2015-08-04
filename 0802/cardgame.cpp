#include<iostream>
using namespace std;

int A[2001];
int B[2001];
int cache[2001][2001] = {0};
int n;

int maxVal(int a, int b) {
    return a>b?a:b;
}

int cardgame(int l, int r, int val) {
    if(r == n || l == n){
        return 0;
    }

    if(A[l] <= B[r]){
        if(cache[l][r] != 0)
            return cache[l][r];
        else
            return cache[l][r] = maxVal(cardgame(l+1, r, val), cardgame(l+1, r+1, val));
    }
    else {
        if(cache[l][r] != 0)
            return cache[l][r];
        else
            return cache[l][r] = cardgame(l, r+1, 0)+B[r];
    }
}

int main() {
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];

    cout<<cardgame(0, 0, 0)<<endl;

    return 0;
}
