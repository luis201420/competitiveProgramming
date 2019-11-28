#include <bits/stdc++.h>

using namespace std;

int main(){
	long long c,n;
	cin >> c >> n;
	n = pow(10,n);
	long long m=1e9;
	long long res,d=c/n;
	if(m>abs((n*d)-c)){
		m=abs((n*d)-c);
		res=n*d;
	}
	d++;
	if(m>=abs((n*d)-c)){
		res+=n;
	}
	cout << res << endl;
	return 0;
}
