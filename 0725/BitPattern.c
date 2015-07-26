#include<stdio.h>

int size, n;
char arr[100];

void backtraking(int k, int l, int o)
{
    int i;
    if(k==size)
    {
        arr[k]=0;
        printf("%s\n",arr);
        return;
    }
    if(l<n)
    {
        arr[k]='1';
        backtraking(k+1,l+1,o);
    }
    if(o)
    {
        arr[k]='0';
        backtraking(k+1,l,o-1);
    }
}
int main()
{
    scanf("%d%d", &size,&n);
    backtraking(0,0,size-n);
    return 0;
}

