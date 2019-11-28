#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a,long long b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(){
	long long n;
	cin >> n;
	long long ans = 0;
	for(long long x = n ; (x*x*x)>ans ; x--){
		for(long long y = x; (x*y*y)>ans ;y--){
			for(long long z = y; (x*y*z)>ans;z--){
				if(gcd(x,y)+gcd(x,z)+gcd(y,z)==3)ans=x*y*z;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
