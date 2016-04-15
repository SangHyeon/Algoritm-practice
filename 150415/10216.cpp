#include <iostream>
#include <vector>
using namespace std;
int n;
vector< pair<int, int> >board;
vector< int > Radius;
vector< int > visited;
int size;

void dfs(int k);

int main() {
    int testcase;
    cin>>testcase;

    for (int i = 0; i < testcase; i++) {
        cin>>n;
        int x, y, r;

        board.clear();
        visited.clear();
        Radius.clear();

        for (int i = 0; i < n; i++) {
            cin>>x>>y>>r;

            board.push_back(make_pair(x, y));
            Radius.push_back(r);
            visited.push_back(0);
        }

        size = board.size();

        int cnt = 0;
        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i);
            }
        }

        cout<<cnt<<endl;
    }
}

void dfs(int k) {
    visited[k] = 1;
    int x1 = board[k].first;
    int y1 = board[k].second;

    for (int i = 0; i < size; i++) {
        int x2 = board[i].first;
        int y2 = board[i].second;
        int dist1 = ((x2-x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1));
        int dist2 = ((Radius[k] + Radius[i])*(Radius[k] + Radius[i]));

        if (!visited[i]  && (dist1 <= dist2))
            dfs(i);
    }

    return;
}

