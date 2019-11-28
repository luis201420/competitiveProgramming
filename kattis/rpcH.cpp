#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main(){
	ld n;
	cin >> n;
	n-=1;

	ld ans=0;
	ld curr=1;
	
	if(n>30) n=30;

	for(long long i=1;i<=n+1;i++){
		ans += 1.0/curr;
		curr *= i;
	}
	stringstream ss;
	ss << abs(ans-(int)ans);
	string s;
	ss >> s;
	int dec = s.length()-2;
	//ans=(int)(ans * pow(10,dec))/100.0;
	if(dec>0)ans+=5.0/pow(10,dec);
	//cerr << ans << endl;
	ans = 1.0-(1.0/ans);
	cout << setprecision(12) << fixed;
	cout << ans << endl;
	return 0;
}
