#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	vector<ll> v(4);
	for(int i=0;i<4;i++)cin >> v[i];
	string s;
	cin >> s;
	ll ans = 0;
	for(int i=0;i<s.size();i++){
		ans+=v[(s[i]-'0')-1];
	}
	cout << ans << "\n";
	return 0;
}
