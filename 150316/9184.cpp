#include<iostream>
using namespace std;

int cache[21][21][21] = {0,};

int recursive(int a, int b, int c);

int main() {

    int a,b,c;

    while(1) {
        cin>>a>>b>>c;
        if(a == -1 && b == -1 && c == -1)
            break;

        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<recursive(a, b, c)<<endl;

        for(int i=0;i<21;i++)
            for(int j=0;j<21;j++)
                for(int k=0;k<21;k++)
                    cache[i][j][k] = 0;
    }

    return 0;
}


int recursive(int a, int b, int c) {
    if(a<=0 || b<=0 || c<=0)
        return 1;
    
    if(a>20 || b>20 || c>20) {
        if(cache[20][20][20] == 0) 
            return cache[20][20][20] = recursive(20, 20, 20);
        else
            return cache[20][20][20];
    }
    
    if(a<b && b<c) {
        int t1,t2,t3;
        if(cache[a][b][c-1] == 0)
            t1 = cache[a][b][c-1] = recursive(a, b, c-1);
        else
            t1 = cache[a][b][c-1];

        if(cache[a][b-1][c-1] == 0)
            t2 = cache[a][b-1][c-1] = recursive(a, b-1, c-1);
        else
            t2 = cache[a][b-1][c-1];

        if(cache[a][b-1][c] == 0)
            t3 = cache[a][b-1][c] = recursive(a, b-1, c);
        else
            t3 = cache[a][b-1][c];

        return t1+t2-t3;
    }
    
    int t1, t2, t3, t4;
    if(cache[a-1][b][c] == 0)
        t1 = cache[a-1][b][c] = recursive(a-1, b, c);
    else
        t1 = cache[a-1][b][c];

    if(cache[a-1][b-1][c] == 0)
        t2 = cache[a-1][b-1][c] = recursive(a-1, b-1, c);
    else 
        t2 = cache[a-1][b-1][c];

    if(cache[a-1][b][c-1] == 0)
        t3 = cache[a-1][b][c-1] = recursive(a-1, b, c-1);
    else
        t3 = cache[a-1][b][c-1];

    if(cache[a-1][b-1][c-1] == 0)
        t4 = cache[a-1][b-1][c-1] = recursive(a-1, b-1, c-1);
    else
        t4 = cache[a-1][b-1][c-1];

    return t1+t2+t3-t4;
}
