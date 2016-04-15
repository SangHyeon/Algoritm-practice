#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, u ,v ,a[51][51], dist[51][51];

void bfs(int s)
{
    dist[s][s] = 0;
    queue< pair<int,int> > q;
    q.push(make_pair(s,0));
    while(!q.empty())
    {
        int here = q.front().first; int step = q.front().second; q.pop();
        for(int i=1;i<=n;i++)
        {
            if(i==s) continue;
            if(a[here][i] == 1 && dist[s][i] == 0)
            {
                dist[s][i] = step+1;
                q.push(make_pair(i, step+1));
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    while(true)
    {
        scanf("%d %d",&u,&v); if(u==-1 || v==-1) break;
        a[u][v] = a[v][u] = 1;

    }
    vector<int> score(n+1);
    int minv = 987654321;
    for(int i=1;i<=n;i++) {
        bfs(i);
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            score[i] = max(score[i], dist[i][j]);
        }
        minv = min(minv,score[i]);
    }

    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(score[i] == minv) ans.push_back(i);
    }

    printf("%d %d\n",minv, ans.size());
    for(int i=0;i<ans.size();i++) printf("%d ", ans[i]);




}

