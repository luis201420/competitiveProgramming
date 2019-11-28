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
	ll n,m,v;
	ll ans1,ans2;
	ans1=ans2=0;
	cin >> n;
	fore(i,0,n){cin >> v;ans1=max(ans1,v);}
	cin >> m;
	fore(i,0,m){cin >> v;ans2=max(ans2,v);}
	cout << ans1 << " " << ans2 << "\n";
	return 0;
}
