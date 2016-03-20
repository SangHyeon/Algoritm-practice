#include<iostream>
#include<string>
using namespace std;

char table[101][101];

int main() {
    string s;
    int R = 0, C;
    cin>>s;

    for(int i=1; i*i<=s.length(); i++)
        R++;
    while(1) {
        if(s.length()%R != 0)
            R--;
        else
            break;
    }
    C = s.length()/R;

    int idx = 0;
    for(int i=0; i<C; i++)
        for(int j=0; j<R; j++) {
            table[j][i] = s[idx]; 
            idx++;
        }

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cout<<table[i][j];

    cout<<endl;
    return 0;
}
