#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<pair<int, int> > > table;

int N, M, n1, n2, w;

bool visit[1010];
int func(int v) {
    visit[v] = true;
    int ret = 0;
    for (int i = 0; i<table[v].size(); i++) {
        int next = table[v][i].first;
        if (!visit[next]) ret += min(table[v][i].second, func(next));
    }
    if (ret == 0) 
        return 987654321;
    else 
        return ret;
}
int main() {
    int caseN;
    cin>>caseN;
    while (caseN--) {
        cin>>N>>M;
        memset(visit, false, N + 1);
        table.resize(N + 1);
        while (M--) {
            cin>>n1>>n2>>w;
            table[n1].push_back(make_pair(n2, w));
            table[n2].push_back(make_pair(n1, w));
        }
        if (N == 1) 
            cout<<0<<endl;
        else
            cout<<func(1)<<endl;
        table.clear();
    }
    return 0;
}
