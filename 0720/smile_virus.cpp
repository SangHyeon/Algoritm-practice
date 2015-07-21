/*

VCPP, GPP에서 사용

*/

#include <iostream>
#include <string>
using namespace std;
struct data {
    int x;
    int y;
    int level;
};
data q1[100001];
int q2[1];
int f1=0,r1=0;

void eq1(data n) {
    q1[r1] = n;
    r1++;
}

data dq1() {
    f1++;
    return q1[f1-1];
}

char table[101][101] = {0,};
int load[101][101]={0,};
int count_ = 1;
int x_s, y_s;

void bomb(int x, int y, int level) {
    load[y][x] = level;
    if((x>=0 && x<y_s && y>=0 && y+1<x_s) && (table[y+1][x] == '1' && (load[y+1][x] == 0))) {
        data temp;
        temp.x = x;
        temp.y = y+1;
        temp.level = level+1;
        eq1(temp);
    }
    if((x>=0 && x<y_s && y-1>=0 && y<x_s) && (table[y-1][x] == '1' && (load[y-1][x] == 0 ))) {
        data temp;
        temp.x = x;
        temp.y = y-1;
        temp.level = level+1;
        eq1(temp);
    }
    if((x>=0 && x+1<y_s && y>=0 && y<x_s) && (table[y][x+1] == '1' && (load[y][x+1] == 0))) {
        data temp;
        temp.x = x+1;
        temp.y = y;
        temp.level = level+1;
        eq1(temp);
    }
    if((x-1>=0 && x<y_s && y>=0 && y<x_s) && (table[y][x-1] == '1' && (load[y][x-1] == 0))) {
        data temp;
        temp.x = x-1;
        temp.y = y;
        temp.level = level+1;
        eq1(temp);
    }
    
        if(f1 != r1) {
            data t;
            t = dq1();
            bomb(t.x, t.y, t.level);
        }
}
int main()
{

    int nCount;     /* 문제의 테스트 케이스 */

    cin >> nCount;  /* 테스트 케이스 입력 */

    for(int itr=0; itr<nCount; itr++)
    {

        cout << "#testcase" << (itr+1) << endl;

        /*

        알고리즘이 들어가는 부분

        */
        
        cin>>x_s>>y_s;

        for(int i = 0; i<y_s; i++)
            for(int j=0; j<x_s; j++)
                cin>>table[j][i];
        int b_x, b_y;
        cin>>b_x>>b_y;
        bomb(b_y-1, b_x-1,1);
        while(1) {
            if(f1 == r1)
                break;
            data t;
            t = dq1();
            bomb(t.x, t.y, t.level);
        }

        for(int i = 0; i<y_s; i++) {
            for(int j=0; j<x_s; j++) {
                if(count_<load[j][i])
                    count_ = load[j][i];
            }
        }
        cout<<count_<<endl;

        count_ = 0;
        for(int i = 0; i<y_s; i++){
            for(int j=0; j<x_s; j++) {
                table[j][i]=0;
                load[j][i]=0;
            }
        }

        f1=0,r1=0;
        count_=0;
    }

    return 0;   /* 반드시 return 0으로 해주셔야합니다. */ 

}

/*
7 13
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 1 1 1 1 0 0
0 0 0 0 1 1 1
0 0 0 0 1 0 0
0 0 1 1 1 0 0
0 0 0 1 1 1 0
0 0 0 1 0 1 0
0 0 0 1 0 1 0
0 0 0 1 0 1 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
3 4
*/
