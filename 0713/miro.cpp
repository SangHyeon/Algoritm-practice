/*

VC, GCC에서 사용

*/

#include <iostream>
using namespace std;

char table[20][20];
int load[20][20]={0, };

void find(int n, int m,int N, int M) {
	if(n+1 < N && (table[n+1][m] != '1')) {
		if(load[n+1][m] > load[n][m]+1 || (load[n+1][m] == 0) ) {
			load[n+1][m] = load[n][m]+1;
			find(n+1, m, N, M);
			
		}
	}
	if(n-1 > -1 && (table[n-1][m] != '1')) {
		if(load[n-1][m] > load[n][m]+1 || (load[n-1][m] == 0)) {
			load[n-1][m] = load[n][m]+1;
			find(n-1, m, N, M);
		}
	}
	if(m+1 < M && (table[n][m+1] != '1')) {
		if(load[n][m+1] > load[n][m]+1 || (load[n][m+1] == 0)) {
			load[n][m+1] = load[n][m]+1;
			find(n, m+1, N, M);
		}
	}
	if(m-1 > -1 && (table[n][m-1] != '1')) {
		if(load[n][m-1] > load[n][m]+1 || (load[n][m-1] == 0)) {
			load[n][m-1] = load[n][m]+1;
			find(n, m-1, N, M);
		}
	}
	//	printf("===========>\n");
		return;
	//}
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	int N, M, result;
	//int load;

	//scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	cin>>nCount;
	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		/*

		알고리즘이 들어가는 부분

		*/
		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				//scanf("%c", &table[i][j]);
				cin>>table[i][j];
			}
		}
		/*
		for(int i=0; i<N; i++)
			scanf("%
		*/
		load[N-1][0] = 1;
		find(N-1, 0, N, M);

		result = load[0][M-1];

		if(result == 0)
			cout<<"-1"<<endl;//printf("-1\n");
		else
			cout<<result<<endl;//printf("%d\n", result);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}
