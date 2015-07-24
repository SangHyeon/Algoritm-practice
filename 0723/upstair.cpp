#include<iostream>
using namespace std;
int stair1[310] = {0, };
int stair2[310] ={0, };
int score[310] = {0, };
int main() {
    int num;
    cin>>num;

    for(int i=0; i<num; i++)
        cin>>score[i];
    stair2[0] = 0;
    stair1[0] = 0;
    stair2[1] = 0;
    stair1[1] = score[0];

    for(int i=2; i<=num; i++) {
        if(stair1[i-2] > stair2[i-2])
            stair1[i] = stair1[i-2] + score[i-1];
        else
            stair1[i] = stair2[i-2] + score[i-1];

        stair2[i] = stair1[i-1] + score[i-1];
    }

    if(stair1[num] > stair2[num])
        cout<<stair1[num]<<endl;
    else
        cout<<stair2[num]<<endl;

    return 0;
}
