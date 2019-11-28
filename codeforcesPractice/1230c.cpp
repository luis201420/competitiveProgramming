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

vvll adj;
vll mask;
ll n;

ll solve(){
	set<pll> ss;
	ll u,v;
	fore(i,0,n){
		u = mask[i];
		fore(j,0,SZ(adj[i])){
			v = mask[adj[i][j]];
			ss.insert({min(u,v),max(u,v)});
		}
	}
	return SZ(ss);
}

int main(){FIN
	ll m,a,b,ans;
	vll g;

	cin >> n >> m;

	adj.assign(n,vll());
	fore(i,0,m){
		cin >> a >> b;
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
	}

	ans = 0;

	fore(a,0,6) fore(b,0,6) fore(c,0,6) fore(d,0,6) fore(e,0,6) fore(f,0,6) fore(g,0,6){
		mask = {a,b,c,d,e,f,g};
		ans = max(ans,solve());
	}

	cout << ans << "\n";
	
	return 0;
}
