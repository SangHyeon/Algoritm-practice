#include<iostream>
using namespace std;

int cache[101][101] ={0, };
int table[101][101] = {0, };
int size;
void dfs(int x, int y, int m) {
    if(cache[x][y] > m)
        return;
    else
        cache[x][y] = m;
    if(x+1<size) {
        dfs(x+1, y, m+table[x+1][y]);
    }
    if(y+1<size) {
        dfs(x, y+1, m+table[x][y+1]);
    }
}

int max(int a, int b) {
    return a>b?a:b;
}

int scv(int x, int y) {
    if(x == size && y == size)
        return table[x][y];
    if(x>size || y>size)
        return 0;

    if(cache[x][y] != 0)
        return cache[x][y];

    return cache[x][y] = table[x][y] + max(scv(x+1,y), scv(x, y+1));
}

int main() {
    cin>>size;

    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            cin>>table[i][j];

    cout<<scv(0, 0)<<endl;


    //Time Limit
/*    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
            cout<<cache[i][j]<<" ";
        cout<<endl;
    }*/
    //cout<<cache[size-1][size-1]<<endl;

    return 0;
}
