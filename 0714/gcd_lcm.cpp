#include<iostream>
using namespace std;

int main() {
	int n, m;
	int max;
	int gcd = 0;
	cin>>n>>m;

	if(n>m)
		max = n;
	else
		max = m;

	for(int i=1; i<max+1; i++) {
		if(n%i == 0 && m%i == 0) {
			if(gcd<i)
				gcd = i;
		}
	}

	cout<<gcd<<" "<<n*m/gcd<<endl;
	return 0;
}
