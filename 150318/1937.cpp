#include<iostream>
#include<deque>
using namespace std;

int table[501][501] = {0,};
int max_v[501][501] = {0,};
int n;
int MAX=0;

void dfs(int x, int y);
struct Point {
    int x, y, level;
};

int main() {
    deque<Point> q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    cin>>n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>table[i][j];

    int visited_level = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            Point start;
            int visited[501][501] = {0,};
            start.x = i;
            start.y = j;
            start.level = 1;
            visited[i][j] = 1;
            q.push_back(start);
            while(!q.empty()) {
                Point cur = q.front();
                q.pop_front();
                for(int k=0; k<4; k++) {
                    int x = cur.x + dx[k];
                    int y = cur.y + dy[k];
                    cout<<"======  "<<i<<" "<<j<<endl;
                    cout<<"---  "<<x<<" "<<y<<endl;
                    cout<<"-=-=-= "<<k<<endl;

                    if(x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && table[i][j] < table[x][y]) {
                        Point t;
                        t.x = x;
                        t.y = y;
                        t.level = cur.level+1;
                        visited[x][y] = 1;
                        q.push_back(t);
                        if(MAX < t.level) {
                            MAX = t.level;
                            cout<<MAX<<endl;
                        }
                    }
                }
            }
        }
    }

    cout<<MAX<<endl;

    return 0;
}
