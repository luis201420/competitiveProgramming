#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main(){
	long long n;
	cin >> n;

	ld ans=0;
	ld curr=1;
	
	if(n>30) n=30;

	for(long long i=1;i<=n+1;i++){
		ans += 1.0/curr;
		curr *= i;
	}
	cout << setprecision(12) << fixed;
	cout << ans << endl;
	return 0;
}
