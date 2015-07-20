#include<iostream>
#include<fstream>
#include<time.h>

using namespace std;

void MergeSort(double num[], int first, int last);
void Merge(double num[], int first, int mid, int last);

int main(int argc, char const *argv[])
{
    double *num;
    int size;
    double start, end;

    cin>>size;
    num = new double[size];
    for(int i=0; i<size; i++)
        cin>>num[i];

    start = clock();

    //코드 작성
    MergeSort(num, 0, size-1);

    end = clock();
    
    for (int i = 0; i < size; i++)
        cout<<num[i]<<" ";
    cout<<endl;

    printf("%f\n\n", (end - start)/CLOCKS_PER_SEC);

    return 0;
}

void MergeSort(double num[], int first, int last)
{
    if(first<last)
    {
        int mid = (first + last)/2;
        MergeSort(num, first, mid);//분할
        MergeSort(num, mid+1, last);
        Merge(num, first, mid, last);//합침
    }
}

void Merge(double num[], int first, int mid, int last)
{
    int f = first;//first~mid
    int l = mid+1;//mid+1~last
    int index=first;//0으로 하면 안됨!
    double temp[last];

    while((f<=mid) && (l<=last))//어느 한 부분이 전부 비교가 끝나면 탈출
    {//두 배열을 서로 비교하면서 임시로 만든 배열에 순서대로 저장
        if(num[f] <= num[l])
        {
            temp[index] = num[f];
            f++;
            index++;
        }
        else
        {
            temp[index] = num[l];
            l++;
            index++;
        }
    }
    //어느 한 부분이 끝난 경우 나머지를 뒤에 이어줌
    if(f > mid)
    {
        for(int i = l; l<=last; l++)
        {
            temp[index] = num[l];
            index++;
        }
    }
    else// if(l < last)
    {
        for(int i = f; f<=mid; f++)
        {
            temp[index] = num[f];
            index++;
        }
    }
    //정렬된 배열을 다시 원래 있던 배열에 복사
    for(int i = first; i<=last; i++)
        num[i] = temp[i];
}
