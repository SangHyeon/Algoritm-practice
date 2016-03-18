#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        string t;
        cin>>t;
        if(t[t.length()-1] == '2' || t[t.length()-1] == '4' || t[t.length()-1] == '6' || t[t.length()-1] == '8' || t[t.length()-1] == '0')
            cout<<"even"<<endl;
        else
            cout<<"odd"<<endl;
    }

    return 0;
}
