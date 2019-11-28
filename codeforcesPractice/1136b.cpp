#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k,mov,p;
	cin >> n >> k;
	mov = n-1;
	p =n;
	if((n+1)/2 <k){
		p+=(n-k+1);
		mov=n-1;
	}
	else{
		p+=(k-1+1);
		mov = (k-1)+(n-k);
	}
	//cerr << p << " " << mov << endl;
	cout << n+(mov)+p << endl;
	return 0;
}
