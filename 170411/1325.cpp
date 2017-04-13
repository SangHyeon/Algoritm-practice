#include<iostream>
#include<deque>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

vector<int> table[10005];
bool visited[10005];
unsigned short result[10005];

int main() {
    int N,M;
    int max_val = 0;
    cin>>N>>M;
    for(int i=0; i<M; i++) {
        int a, b;
        cin>>a>>b;
        table[b].push_back(a);
    }

    for(int i=1; i<=M; i++) {
        memset(visited, false, sizeof(visited));
        deque<int> q;
        q.push_back(i);

        while(!q.empty()) {
            int t = q.front();
            q.pop_front();
            visited[t] = true;

            for(int j=0; j<table[t].size(); j++) {
                if(visited[table[t][j]] == true)
                    continue;
                q.push_back(table[t][j]);
                result[i]++;
                if(max_val < result[i])
                    max_val = result[i];
            }
        }
    }

    for(int i=1; i<=N; i++) {
        if(max_val == result[i]) {
            cout<<i<<" ";
        }
    }
    cout<<endl;

    return 0;
}
