#include<iostream>
using namespace std;


int graph[101][101];

int visited[101];
int q[1000];
int front, rear;

int count;
void enq(int n) {
	rear++;
	q[rear] = n;
}

int deq() {
	front--;
	return q[front-1];
}

int q2[1000];
int front2, rear2;
void enq2(int n) {
	rear2++;
	q[rear2] = n;
}

int deq2() {
	front2--;
	return q[front2-1];
}

void bfs(int x, int y, int level) {
	graph[x][y] = level;
	for(int i=0; i<=x;i++)
		if(graph[x][i] < 999) {
			enq(x);
			enq2(i);
		}
	if(front != rear)
		bfs(deq(), deq2(), level+1);
}

int size;
int buile;

int table[100][100]={0};
int v[100][100] = {0};

void find(int x, int y) {
	v[x][y] = 1;
	if(x<size && y<size) {
		

	}
}

int main() {
	cin>>size;
	int x, y;
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++) {
			cin>>x;
			if(x == 1)
				graph[i][j] = 999;
			else
				graph[i][j] = x;
		}
	}

	cin>>x>>y;


	return 0;
}
