#include <bits/stdc++.h>

#define FIN ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define pb push_bask
#define ALL(s) s.begin(),s.end()

using namespace std;

typedef long long ll;

int main(){FIN
	int q;
	ll a,b,c;
	cin >> q;
	while(q--){
		cin >> a >> b >> c;
		cout << (a+b+c)/2 << "\n";
	}
	return 0;
}
