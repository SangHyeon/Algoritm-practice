#include<iostream>
using namespace std;

int table[10][10]={0};
bool visited[10] = {false};
void dfs(int n) {
	visited[n-1] = true;
	cout<<n<<" ";
	for(int i=0; i<10; i++) {
		if(table[n-1][i] == 1 && !visited[i]) {
			dfs(i+1);
		}
	}
}

int main() {
	int x, y;
	while(scanf("%d %d", &x, &y) != EOF) {
	//	cin>>x>>y;
		table[x][y] = table[y][x] = 1;
	}

	dfs(1);
	cout<<endl;
	return 0;
}
