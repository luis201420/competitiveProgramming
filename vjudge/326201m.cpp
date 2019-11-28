#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

#define SQR(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 11

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<string> vstr;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<vbool> vvbool;

int main(){FIN
	ll n,k,x,y,m,s,ans;
	vll ns;

	cin >> n >> k;
	ns.resize(n);
	fore(i,0,n) cin >> ns[i];
	x = 0, y = 0;
	s = 0;
	m = 1e9;
	while(x <= (n-k)){
		while(y<n && (y-x)<k){
			s+= ns[y];
			y++;
		}
		if(s < m){
			m = s;
			ans = x;
		}
		s-=ns[x];
		x++;
	}
	cout << ans+1 << "\n";
	return 0;
}
