#include<iostream>
#include<deque>
using namespace std;
struct data{
    int x;
    int y;
    int wall;
};

int main() {
    int table[51][51] = {0};
    int cache[51][51] = {0};
    int n;
    int result = -1;
    char temp[51];
    int dx[] = {0, -1, 0, 1};
    int dy[] = {1, 0, -1, 0};
    
    deque<data> q;
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp;
        for(int j=0;j<n; j++){
            table[i][j] = temp[j]-'0';
            if(table[i][j] == 0)
                table[i][j] = 1;
            else
                table[i][j] = 0;
            cache[i][j] = -1;
        }
    }
 
    data start;
    start.x = 0;
    start.y = 0;
    start.wall = table[0][0];

    q.push_back(start);
    while(!q.empty()) {
        data t = q.front();
        q.pop_front();
        for(int i=0; i<4; i++) {
            if(t.x + dx[i] < n && t.x + dx[i] >= 0 && t.y + dy[i] < n && t.y + dy >= 0 && \
                    (cache[t.x + dx[i]][t.y + dy[i]] == -1 || \
                     t.wall+table[t.x+dx[i]][t.y+dy[i]] < cache[t.x+dx[i]][t.y+dy[i]])) {
                data a;
                a.x = t.x + dx[i];
                a.y = t.y + dy[i];
                a.wall = t.wall + table[a.x][a.y];
                cache[a.x][a.y] = a.wall;
                q.push_back(a);
            }
        }
    }

    cout<<cache[n-1][n-1]<<endl;
    
    return 0; 
}
