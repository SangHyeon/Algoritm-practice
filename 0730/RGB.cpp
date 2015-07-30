#include<iostream>
using namespace std;

int table[3][1001] = {0};
int val[3][1001] = {0};

int minishell(int a, int b) {
    return a<b?a:b;
}

int main() {
    int n;
    int result;
    cin>>n;

    for(int i=0;i<n; i++)
        for(int j=0; j<3; j++)
            cin>>table[j][i];

    val[0][0] = table[0][0];
    val[1][0] = table[1][0];
    val[2][0] = table[2][0];

    for(int i=1; i<n; i++) {
        for(int j=0; j<3; j++) {
            val[j][i] = table[j][i] + minishell(val[(j+1)%3][i-1], val[(j+2)%3][i-1]);
        }
    }

/*    for(int i=0; i<3; i++) {
        for(int j=0; j<n; j++)
            cout<<val[i][j]<<" ";
        cout<<endl;
    }
*/
    result = val[0][n-1];
    for(int i=1; i<3; i++) {
        if(val[i][n-1] < result)
            result = val[i][n-1];
    }

    cout<<result<<endl;

    return 0;
}
