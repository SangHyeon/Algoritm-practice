#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int It=0; It<n; It++){
        string s[12];
        int x,y;
        cin>>x>>y;
        for(int i=0; i<x; i++)
        {
            cin>>s[i];
        }

        for(int i=x-1; i>=0; i--)
            cout<<s[i]<<endl;
    }

    return 0;
}
