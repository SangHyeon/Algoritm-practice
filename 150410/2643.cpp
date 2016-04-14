#include<iostream>
#include<algorithm>
using namespace std;
struct paper {
    int w, h;
};
int n;
paper p[101];
int cache[101] = {0, };

bool cmp(paper a, paper b) {
    if(a.w > b.w)
        return false;
    else if(a.w == b.w) {
        if(a.h > b.h)
            return false;
        return true;
    }
    return true;
}

int sol(int idx) {
    if(idx == n)
        return 0;

    if(cache[idx] != 0)
        return cache[idx];
    int r=0;
    for(int i=idx+1; i<n; i++) {
        //if(!(p[idx].w <= p[i].w && p[idx].h <= p[i].h))
        //    continue;
        if(p[idx].w < p[i].w && p[idx].h <= p[i].h)
            r = max(1+sol(i), r);
        else if(p[idx].w == p[i].w && p[idx].h < p[i].h)
            r = max(1+sol(i), r);
        else
            continue;
    }
    return cache[idx] = r;
}
int main() {
    cin>>n;
    for(int i=0; i<n; i++) {
        paper t;
        int w, h;
        cin>>w>>h;
        if(w > h) {
            t.w = w;
            t.h = h;
            p[i] = t;
        }
        else {
            t.w = h;
            t.h = w;
            p[i] = t;
        }
    }

    sort(p, p+n, cmp);

   /* cout<<endl<<endl;
    for(int i=0; i<n; i++)
        cout<<p[i].w<<" "<<p[i].h<<endl;
    */
    int r=0;
    for(int i=0; i<n; i++)
        r = max(sol(i), r);
    cout<<r+1<<endl;
    return 0;
}
