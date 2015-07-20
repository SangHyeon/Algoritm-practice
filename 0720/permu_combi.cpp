#include <iostream>
using namespace std;
#define SWAP(a,b) {int tmp = a; a = b; b = tmp;}
int nop = 0; // number of permutation
int of = 0; // order first
int os = 0; // order second

void permutation(char *str1, int maxNumber,int maxCase, int numberCase){
 char str[20];
 strcpy(str,str1);
 if(numberCase == maxCase )
 {
  str[maxCase] = 0;
  //cout << str<< endl;
  nop++;
  if( nop == of ){
   cout << str << endl;
  }
  return;
 }
 for(int i = numberCase; i < maxNumber; i++){
  SWAP(str[i],str[numberCase])
  permutation(str,maxNumber,maxCase,numberCase+1);
 }
}

void combination(char *str1, int maxNumber,int maxCase, int numberCase){
 char str[20];
 strcpy(str,str1);

 if(numberCase == maxCase )
 {
  str[maxCase] = 0;
  nop++;
  if( nop == os ){
   cout << str << endl;
  }
  return;
 }
 for(int i = numberCase; i < maxNumber; i++){
  //if(str[i] < str[numberCase])
  SWAP(str[i],str[numberCase])
  if(str[numberCase-1] > str[numberCase] && numberCase)
   continue;
  combination(str,maxNumber,maxCase,numberCase+1);
 }
 
}

int main()
{
 int nCount;  /* 문제의 테스트 케이스 */
 cin >> nCount; /* 테스트 케이스 입력 */
 for(int itr=0; itr<nCount; itr++)
 {
  cout << "#testcase" << (itr+1) << endl;
  int now = 0;// number of word
  int nos = 0; // number of selection

  cin >>now >> nos >> of >> os;
  char str[20];
  int i =0;
  for( i= 0; i < now; i++)
  {
   str[i] = i+'A';
  }
  str[i] = 0;
  nop = 0;
  permutation(str,now,nos,0);
  nop = 0;
  combination(str,now,nos,0);
 }
 return 0; /* 반드시 return 0으로 해주셔야합니다. */
}
