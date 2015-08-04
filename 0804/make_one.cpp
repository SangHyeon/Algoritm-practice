#include<iostream>
using namespace std;

struct data{
    int n;
    int level;
};
data q[1000001] = {0};
int visited[1000001] = {0};

int f=0, r=0;

void eq(data n) {
    q[r] = n;
    r++;
    r%=1000001;
}

data dq() {
    int temp = f;
    f++;
    f%=1000001;
    return q[temp];
}

bool isEmpty(){
    if(r == f)
        return false;
    else
        return true;
}

int main() {
    int n;
    int result;
    data d;
    cin>>n;

    d.n = n;
    d.level = 0;
    
    eq(d);
    visited[d.n] = 1;
    while(isEmpty()) {
        data t = dq();
        if(t.n == 1) {
            result = t.level;
            break;
        }
        if(t.n%3 == 0 && visited[t.n/3] == 0) {
            data tmp = t;
            tmp.n = t.n/3;
            tmp.level = t.level+1;
            eq(tmp);
            visited[tmp.n] = 1;
        }
        if(t.n%2 == 0 && visited[t.n/2] == 0) {
            data tmp = t;
            tmp.n = t.n/2;
            tmp.level = t.level+1;
            eq(tmp);
            visited[tmp.n] = 1;
        }
        if(t.n-1 != 0 && visited[t.n-1] == 0) {
            data tmp = t;
            tmp.n = t.n-1;
            tmp.level = t.level+1;
            eq(tmp);
            visited[tmp.n] = 1;
        }
    }

    cout<<result<<endl;
    return 0;
}
