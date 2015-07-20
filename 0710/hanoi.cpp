#include<iostream>
using namespace std;

int hanoi(int n) {
	if(n == 1)
		return 1;
	return (2*(hanoi(n-1))+1);

}

int main(int argc, char* argv[]) {
	int result;
	int k;
	k = atoi(argv[1]);
	result=hanoi(k);

	cout<<result<<endl;
	return 0;
}
