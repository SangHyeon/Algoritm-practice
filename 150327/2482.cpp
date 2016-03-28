#include<iostream>
using namespace std;

#define MOD 1000000003

int color[1001] = {0, };
int cache[1001][1001][2] = {0, };
int n, k;

int sol(int start, int selected, int first) {
    if(selected == k)
        return 1;
    if(start >= n)
        return 0;
    int &ret = cache[start][selected][first];
    if(ret != -1)
        return ret;

    ret = 0;

    if(start == n-1) {
        if(first == 1)
            return 0;
        return ret = (sol(start+1, selected, first) + sol(start+2, selected+1, first))%MOD;
    }

    if(start == 0) 
        ret = (ret + sol(start+2, selected+1, 1))%MOD;
    else
        ret = (ret + sol(start+2, selected+1, first))%MOD;

    if(start == 0)
        ret = (ret + sol(start+1, selected, 0))%MOD;
    else
        ret = (ret + sol(start+1, selected, first))%MOD;
    return ret;
}

int main() {
    cin>>n>>k;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int a=0; a<2; a++)
                cache[i][j][a] = -1;

    cout<<sol(0, 0, 0)<<endl;

    return 0;
}
