#include <iostream>
using namespace std;
bool check(int arr[64][64], int si, int sj, int fi, int fj, int gap){
    for(int i=si; i<=fi; i++){
        for(int j=sj; j<=fj; j++){
            if(arr[i][j] != gap)return false;
        }
    }
    return true;
}
void q(int arr[64][64], int si, int sj, int fi, int fj){
    if(check(arr, si, sj, fi, fj, 1)){
        cout<<1;
        return;
    }
    if(check(arr, si, sj, fi, fj, 0)){
        cout<<0;
        return;
    }

    int midi = (si + fi)/2;
    int midj = (sj + fj)/2;
    cout<<"(";
    q(arr,si,sj,midi,midj);
    q(arr,si,midj+1,midi,fj);
    q(arr,midi+1,sj,fi,midj);
    q(arr,midi+1, midj+1, fi, fj);
    cout<<")";
}
int main(){
    int n;
    int arr[64][64]={0};
    char temp;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>temp;
            arr[i][j] = temp - '0';
        }
    }
    q(arr,0,0,n-1,n-1);
    //getchar();
    //getchar();
    return 0;
}
