#include<iostream>
using namespace std;
 
int main(){
 
    int k, t = 0;
    while (scanf("%d", &k), k != 0){
        t++;
        int sum[3] = { 0, };
        for (int I = 0; I < k; I++){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            int temp[3] = { 0, };
            if (I == 0){
                sum[1] = b;
                sum[2] = c;
                sum[2] = sum[1] + sum[2];
            }
            else if (I == 1){
                temp[0] = sum[1] + a;
                temp[1] = min(sum[1], min(temp[0], sum[2])) + b;
                temp[2] = min(sum[1], min(temp[1], sum[2])) + c;
                for (int i = 0; i < 3; i++){
                    sum[i] = temp[i];
                }
            }
            else{
                temp[0] = min(sum[0], sum[1]) + a;
                temp[1] = min(sum[0], min(sum[1], min(sum[2],temp[0]))) + b;
                temp[2] = min(sum[1], min(sum[2], temp[1])) + c;
                for (int i = 0; i < 3; i++){
                    sum[i] = temp[i];
                }
            }
        }
        printf("%d. %d\n", t, sum[1]);
    }
 
    return 0;
}
