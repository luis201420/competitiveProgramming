#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fact(ll a){
	ll res=1;
	for(ll i=2;i<=a;i++){
		res*=i;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	while(cin >> n >> m){
		cout << fact(n)+fact(m) << endl;
	}
	return 0;
}
