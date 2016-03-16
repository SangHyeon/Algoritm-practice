#include<iostream>
#include<string>
using namespace std;

char table[101][101];

int main() {
    int w,h;
    cin>>w>>h;

    for(int i=0; i<w; i++) 
        for(int j=0; j<h; j++) 
            cin>>table[i][j];

    for(int k=0; k<w; k++) {
        int j=0;
        for(int i=h; i<h*2; i++) {
            table[k][i] = table[k][h-1-j];
            j++;
        }
    }

    int j = w-1;
    for(int k=w; k<2*w; k++) {
        for(int i=0; i<2*h; i++) {
            table[k][i] = table[j][i];
        }
        j--;
    }

    int x, y;
    cin>>x>>y;

    if(table[x-1][y-1] == '#')
        table[x-1][y-1] = '.';
    else
        table[x-1][y-1] = '#';

    for(int i=0; i<2*w; i++) {
        for(int j=0; j<2*h; j++)
            cout<<table[i][j];
        cout<<endl;
    }


    return 0;
}
