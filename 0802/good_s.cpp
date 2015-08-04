#include<stdio.h>
int good[100], n, sum, chk;
int check(int a)
{
    int i, j, c=0;
    for(i=1 ; i<=a/2 ; i++)
    {
        c=0;
        for(j=0 ; j<i ; j++)
        {
            if(good[a-j]==good[a-i-j])
                c++;
        }
        if(c==i)
            return 0;
    }
    return 1;
}
int gs(int cnt, int num)
{
    int chk=0, i;
    good[cnt]=num;
    sum=check(cnt);
    if(sum==0)
        return 0;
    if(cnt==n)
        return 1;
    for(i=1 ; i<=3 ; i++)
    {
        if(gs(cnt+1, i)==1)
        {
            chk=1;
            break;
        }
    }
    if(chk==0)
        return 0;
    return 1;
}
int main()
{
    int i;
    scanf("%d", &n);
    gs(1, 1);
    for(i=1 ; i<=n ; i++)
    {
        printf("%d", good[i]);
    }
    return 0;
}
