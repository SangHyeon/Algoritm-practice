#include<iostream>
using namespace std;

int s1[301] = {0, };
int s2[301] = {0, };
int stair[301];
int n;

int main() {
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>stair[i];

    s1[1] = stair[1];
    
    for(int i=2; i<=n; i++) {
        if(s1[i-2] > s2[i-2]) 
            s1[i] = s1[i-2] + stair[i];
        else
            s1[i] = s2[i-2] + stair[i];
        s2[i] = s1[i-1] + stair[i];
    }

    if(s1[n] > s2[n])
        cout<<s1[n]<<endl;
    else
        cout<<s2[n]<<endl;

    return 0;
}
