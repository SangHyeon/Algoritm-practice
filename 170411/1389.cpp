#include<iostream>
#include<deque>
#include<vector>
#include<cstdio>
#include<cstring>

#define INF 999999999

using namespace std;

struct Data {
    int pos;
    int level;
};
vector<int> table[101];
deque<Data> q;
int visited[101];
int result[101];
int main() {
    int N, M;
    int num = INF;
    cin>>N>>M;

    for(int i=0; i<M; i++) {
        int x, y;
        cin>>x>>y;
        table[x].push_back(y);
        table[y].push_back(x);
    }

    for(int i=1; i<=N; i++) {
        int t_cnt = 0;
        Data data;
        data.pos = i;
        data.level = 0;
        memset(visited, -1, sizeof(visited));
        
        q.push_back(data);
        visited[i] = 0;
        while(!q.empty()) {
            Data a = q.front();
            q.pop_front();
            int pos = a.pos;
            for(int j=0; j<table[pos].size(); j++) {
                if(visited[table[pos][j]] == -1) {
                    visited[table[pos][j]] = a.level + 1;
                    Data tmp;
                    tmp.pos = table[pos][j];
                    tmp.level = a.level + 1;

                    q.push_back(tmp);
                }
            }
        }
        int sum = 0;
        for(int k=1; k<=N; k++) {
            sum+=visited[k];
        }
        result[i] = sum;
    }

    int sum = INF;
    for(int i=1; i<=N; i++) {
        if(sum > result[i]) {
            sum = result[i];
            num = i;
        }   
    }
    cout<<num<<endl;

    return 0;
}
