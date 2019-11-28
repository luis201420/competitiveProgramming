#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n,res,d;
	cin >> n;
	res=1e9;
	for(long long i=1;i<=sqrt(n);i++){
		d=ceil(double(n)/double(i));
		if((i+d)<res)res=(i+d);
	}
	cout << res << endl;
	return 0;
}
