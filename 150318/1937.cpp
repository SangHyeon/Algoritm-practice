#include<iostream>
using namespace std;

int table[501][501] = {0,};
int visited[501][501] = {0,};
int max_v[501][501] = {0,};
int n;
int MAX=0;

void dfs(int x, int y);

int main() {
    cin>>n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>table[i][j];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visited[i][j] = 1;
            dfs(i, j);/*
            for(int k=0;k<n;k++)
                for(int l=0;l<n;l++)
                    visited[k][l] = 0;
                    */
        }
    }

    cout<<MAX<<endl;

    return 0;
}

void dfs(int x, int  y) {
    if(x+1 < n && table[x+1][y] > table[x][y] && visited[x][y+1] < visited[x][y]+1 && max_v[x+1][y] < visited[x][y]+1) {
        max_v[x+1][y] = visited[x+1][y] = visited[x][y] + 1;
        dfs(x+1, y);
        if(MAX < max_v[x+1][y])
            MAX = max_v[x+1][y];
    }
    if(y+1 < n && table[x][y+1] > table[x][y] && visited[x][y+1] < visited[x][y]+1 && max_v[x][y+1] < visited[x][y]+1) {
        max_v[x][y+1] = visited[x][y+1] = visited[x][y] + 1;
        dfs(x, y+1);
        if(MAX < max_v[x][y+1])
            MAX = max_v[x][y+1];
    }
    if(x-1 >= 0 && table[x-1][y] > table[x][y] && visited[x-1][y] < visited[x][y]+1 && max_v[x+-1][y] < visited[x][y]+1) {
        max_v[x-1][y] = visited[x-1][y] = visited[x][y] + 1;
        dfs(x-1, y);
        if(MAX < max_v[x-1][y])
            MAX = max_v[x-1][y];
    }
    if(y-1 >= 0 && table[x][y-1] > table[x][y] && visited[x][y-1] < visited[x][y]+1 && max_v[x][y-1] < visited[x][y]+1) {
        max_v[x][y-1] = visited[x][y-1] = visited[x][y] + 1;
        dfs(x, y-1);
        if(MAX < max_v[x][y-1])
            MAX = max_v[x][y-1];
    }
}
