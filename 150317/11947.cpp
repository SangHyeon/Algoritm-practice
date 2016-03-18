#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int CaseNum = 0; CaseNum<n; CaseNum++) {
        unsigned long long num, num2, temp, max = 0;
        cin>>num;
        int digit = 1;
        temp = num;

        while(1) {
            if(temp/10 > 0) 
                digit++;
            else
                break;
            temp /= 10;
        }
        temp = 1;
        for(int i=0; i<digit; i++) 
            temp *= 10;

        if(temp/2 < num)
            num = temp/2 - 1;

        num2 = temp - num - 1;
       
        cout<<num*num2<<endl;
    }

    return 0;
}
