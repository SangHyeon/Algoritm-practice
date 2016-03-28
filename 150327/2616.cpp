#include<iostream>
using namespace std;

int train[50001] = {0, };
int cache[50001][3] = {0, };
int n, m;
int sol(int start, int tr) {
    if(tr > 2)
        return 0;
    if(start + m  > n)
        return 0;
    int &ret = cache[start][tr];
    if(ret != 0)
        return ret;

    //cout<<"S : "<<start<<"   TR : "<<tr<<"  m = "<<m<<endl;
    int temp = 0;
    for(int i=0; i<m; i++)
        temp += train[start+i];

    ret = max(sol(start+1, tr), (temp+sol(start+m, tr+1)));
    return ret;
}

int main() {
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>train[i];
    cin>>m;

    cout<<sol(0, 0)<<endl;
    /*for(int i=0; i<3; i++) {
        for(int j=0; j<n; j++)
            cout<<cache[i][j]<<" ";
        cout<<endl;
    }*/

    return 0;
}
