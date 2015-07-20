#include <iostream>
using namespace std;
int main()
{

    int nCount;      /* 문제의 테스트 케이스 */

    cin >> nCount;   /* 테스트 케이스 입력 */

    for(int itr=0; itr<nCount; itr++)
    {

        cout << "#testcase" << (itr+1) << endl;

        int gcd, lcm;
        cin >> gcd >> lcm;
        //최대공약수와 최소공배수 입력
        //입력받은 gcd와 lcm을 만족하는 합이 제일 작은 두 자연수
        int num = lcm / gcd;

        int max = 1;
        for(int i=2; i*i <= num; i++){//root num
            int flag = 0;
            if(num % i == 0 ){
                for(int j=2; j*j<= i; j++){
                    if(i % j == 0 && (num/i) % j == 0){
                        flag = 1;
                        break;
                    }
                }

                if(flag)
                    continue;

                max = i;
            }
        }

        cout << max * gcd << " " << (num / max) * gcd << endl;



    }

    return 0;   /* 반드시 return 0으로 해주셔야합니다. */ 

}
