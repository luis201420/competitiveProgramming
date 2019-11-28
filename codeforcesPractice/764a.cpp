#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n,m,z,ans=0;
	cin >> n >> m >> z;
	for(int i=1;i<=z;i++){
		if(i%n==0 && i%m==0)ans++;
	}
	cout << ans << "\n";
	return 0;
}
