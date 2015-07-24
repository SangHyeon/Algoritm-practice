#include<iostream>
using namespace std;

int table[301][21] ={0, };
int invest[301][21] = {0, };
int tracking[301][21] = {0, };
int main() {
    int M, N;
    cin>>M>>N;

    for(int i=1; i<M+1; i++) 
        for(int j=0; j<N; j++)
            cin>>table[i][j];
    
    for(int i=1; i<M+1;i++)
        invest[i][0] = table[i][0];

    for(int i=0; i<M+1; i++){
        for(int j=1; j<N; j++) {
            int max = table[i][j];
            int l = i;
            for(int k=0; k<i+1; k++) {
                if(invest[k][j-1] + table[l][j] > max)
                    max = invest[k][j-1]+table[l][j];
                l--;
            }
            invest[i][j] = max;
        }
    }

    cout<<invest[M][N-1]<<endl;

    return 0;
}
