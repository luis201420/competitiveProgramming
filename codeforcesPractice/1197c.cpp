#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){FIN
	
	ll n, k, ans;
	vll ns,d;

	cin >> n >> k;
	ns.resize(n);
	fore(i,0,n)cin >> ns[i];
	fore(i,1,n) d.pb(ns[i-1]-ns[i]);
	sort(ALL(d));

	ans = ns[n-1]-ns[0];
	fore(i,0,k-1) ans += d[i];

	cout << ans << "\n";

	return 0;
}
