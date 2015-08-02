#include<iostream>
using namespace std;

int table[1001][1001];
int visited[1001][1001] = {0};
struct data {
    int x;
    int y;
    int level;
};
int r=0;
int f=0;

data q[100001]={0};

void eq(data n) {
    q[r] = n;
    r++;
    r%=100001;
}

data dq() {
    data temp = q[f];
    f++;
    f%=100001;
    return temp;
}

int main() {
    int n,m;
    int result = 0;
    int gooood = 0;
    cin>>m>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>table[i][j];
            if(table[i][j] == 0 || table[i][j] == -1)
                gooood = 1;
        }
    }

    if(gooood == 0) 
        cout<<0<<endl;
    else {
        int level = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(table[i][j] == level) {
                    data temp;
                    temp.x = i;
                    temp.y = j;
                    temp.level = level;
                    eq(temp);
                    visited[i][j] = level;
                }
            }
        }
        while(r!=f) {
            data temp;
            int i, j;
            temp = dq();
            i = temp.x;
            j = temp.y;
            //if(visited[i][j] == 0)
            //    visited[i][j] = temp.level;
            //cout<<"=====> "<<visited[i][j]<<endl;

            if(i+1<n && i>=0 && j<m && j>=0 && visited[i+1][j] == 0 && table[i+1][j] != -1) {
                data tmp;
                tmp.x = i+1;
                tmp.y = j;
                tmp.level = visited[i][j] + 1;
                visited[i+1][j] = visited[i][j] + 1;

                eq(tmp);
            }
            if(i<n && i-1>=0 && j<m && j>=0 && visited[i-1][j] == 0 && table[i-1][j] != -1) {
                data tmp;
                tmp.x = i-1;
                tmp.y = j;
                tmp.level = visited[i][j] + 1;
                visited[i-1][j] = visited[i][j] + 1;

                eq(tmp);
            }
            if(i<n && i>=0 && j+1<m && j>=0 && visited[i][j+1] == 0 && table[i][j+1] != -1) {
                data tmp;
                tmp.x = i;
                tmp.y = j+1;
                tmp.level = visited[i][j] + 1;
                visited[i][j+1] = visited[i][j] + 1;

                eq(tmp);
            }
            if(i<n && i>=0 && j<m && j-1>=0 && visited[i][j-1] == 0 && table[i][j-1] != -1) {
                data tmp;
                tmp.x = i;
                tmp.y = j-1;
                tmp.level = visited[i][j] + 1;
                visited[i][j-1] = visited[i][j] + 1;

                eq(tmp);
            }
        }
        int bad = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                if(result < visited[i][j])
                    result = visited[i][j];
                if(visited[i][j] == 0 && table[i][j] == 0) {
                    bad = 1;
                    break;
                }
//                cout<<visited[i][j]<<" ";
            }
  //         cout<<endl;
        }
        if(bad == 0)
            cout<<result-1<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
