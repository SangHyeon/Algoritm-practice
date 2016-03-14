#include<iostream>
using namespace std;

int main() {
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;

    int cnt = 0;
    int find = 0;

    while(s<g) {
        if(u == 0)
            break;

        s += u;
        cnt++;
    }

    while(1) {
        if(s<g) 
            break;
        
        if(s == g) {
            find = 1;
            break;
        }

        if(d == 0)
            break;
        s -= d;
        cnt++;
    }

    if(find)
        cout<<cnt<<endl;
    else
        cout<<"use the stairs"<<endl;

    return 0;
}
