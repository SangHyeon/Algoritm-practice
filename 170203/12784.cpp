#include<iostream>
#include<algorithm>
#include<vector>
//#include<stdio.h>
//#include<string>
//#include<cmath>
using namespace std;

vector <pair<int, int> > Table[1001];
int cache[1001];
int degree[1001];

int find(int start, int parent);

int main() {
    int t, N, M;
    cin>>t;
    
    for(int iT=0; iT<t; iT++) {
        //start
        for(int j=0;j<1001;j++) {
            cache[j] = -1;
            degree[j] = 0;
            Table[j].clear();
        }
        cin>>N>>M;

        for(int i=0; i<M; i++) {
            //node1, node2, weight
            int n1, n2, w;
            cin>>n1>>n2>>w;
            Table[n1].push_back(make_pair(n2, w));
            Table[n2].push_back(make_pair(n1, w));

            degree[n1]++;
            degree[n2]++;
        }

        //algorithm start
        int result = find(1, -1);
        cout<<result<<endl;
    }

    return 0;
}

int find(int start, int parent) {
    int& ret = cache[start];
    if(ret != -1)
        return ret;

    if(degree[start] == 1 && start != 1) //except case...
        return 999999999;

    ret = 0;
    for(int i=0; i<Table[start].size(); i++) {
        if(parent == Table[start][i].first)//already visited
            continue;

        ret += min(Table[start][i].second, find(Table[start][i].first, start));
    }

    return ret;
}
