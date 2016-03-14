#include<iostream>
#include<deque>
#include<string>
using namespace std;

struct Point {
    int x, y, level;
};
int table[101][101] = {0,};
int visited[101][101] = {0,};

int main() {
    deque<Point> q;
    int w, h;
    string s;
    cin>>w>>h;
    for(int i=0; i<w; i++) {
        cin>>s;
        for(int j=0; j<h; j++) {
            if(s[j] == '0')
                table[i][j] = 0;
            else
                table[i][j] = 1;
        }
    }

    Point p;
    p.x = 0; p.y = 0; p.level = 1;
    visited[0][0] = 1;
    
    q.push_back(p);

    while(!q.empty()) {
        Point t = q.front();
        q.pop_front();
        if(t.x+1 < w && table[t.x+1][t.y] == 1) {
            if(visited[t.x+1][t.y] == 0 || visited[t.x+1][t.y] > t.level+1) {
                Point temp;
                temp.x = t.x+1; temp.y = t.y; temp.level = t.level+1;
                visited[t.x+1][t.y] = t.level+1;
                q.push_back(temp);
            }
        }
        if(t.x-1 >= 0 && table[t.x-1][t.y] == 1) {
            if(visited[t.x-1][t.y] == 0 || visited[t.x-1][t.y] > t.level+1) {
                Point temp;
                temp.x = t.x-1; temp.y = t.y; temp.level = t.level+1;
                visited[t.x-1][t.y] = t.level+1;
                q.push_back(temp);
            }
        }
        if(t.y+1 < h && table[t.x][t.y+1] == 1) {
            if(visited[t.x][t.y+1] == 0 || visited[t.x][t.y+1] > t.level+1) {
                Point temp;
                temp.x = t.x; temp.y = t.y+1; temp.level = t.level+1;
                visited[t.x][t.y+1] = t.level+1;
                q.push_back(temp);
            }
        }
        if(t.y-1 >= 0 && table[t.x][t.y-1] == 1) {
            if(visited[t.x][t.y-1] == 0 || visited[t.x][t.y-1] > t.level+1) {
                Point temp;
                temp.x = t.x; temp.y = t.y-1; temp.level = t.level+1;
                visited[t.x][t.y-1] = t.level+1;
                q.push_back(temp);
            }
        }
    }

    cout<<visited[w-1][h-1]<<endl;

    return 0;
}
