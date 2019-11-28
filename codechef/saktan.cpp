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
	ll t,n,m,q,x,y,ans;
	pll rr,cc;
	vll r,c;

	cin >> t;
	while(t--){
		cin >> n >> m >> q;
		r.assign(n,0);
		c.assign(m,0);
		while(q--){
			cin >> x >> y;
			r[x-1]++;
			c[y-1]++;
		}
		ans = 0;
		rr = {0,0};
		fore(i,0,n){
			if(r[i]&1)rr.snd++;
			else rr.fst++;
		}
		cc = {0,0};
		fore(i,0,m){
			if(c[i]&1)cc.snd++;
			else cc.fst++;
		}
		ans = (rr.fst*cc.snd)+(rr.snd*cc.fst);
		/*fore(i,0,n){
			fore(j,0,m){
				ans+=((r[i]+c[j])&1);
			}
		}*/
		cout << ans << "\n";
	}
	return 0;
}
