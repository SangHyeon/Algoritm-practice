#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    queue<pair<int, int> > que;
    int n, m;
    char temp;
    int arr[103][103] = { 0 };

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> temp;
            arr[i][j] = temp - '0';
        }
    }

    que.push(make_pair(1, 1));
    arr[1][1] = 2;
    int maxgap = -2000000000;

    while (!que.empty()){
        int i = que.front().first;
        int j = que.front().second;
        que.pop();

        if (arr[i + 1][j] == 1){
            que.push(make_pair(i + 1, j));
            arr[i + 1][j] = arr[i][j] + 1;
        }
        if (arr[i - 1][j] == 1){
            que.push(make_pair(i - 1, j));
            arr[i - 1][j] = arr[i][j] + 1;
        }
        if (arr[i][j + 1] == 1){
            que.push(make_pair(i, j + 1));
            arr[i][j + 1] = arr[i][j] + 1;
        }
        if (arr[i][j - 1] == 1){
            que.push(make_pair(i, j - 1));
            arr[i][j - 1] = arr[i][j] + 1;
        }
    }

    cout << arr[n][m]-1;

    //getchar();
    //getchar();
    return 0;
}
