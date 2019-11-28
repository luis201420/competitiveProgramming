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
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<string> vstr;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;

vvpll adj;
vll dist;
ll n,m;

void bford(ll s){
	dist[s]=0;
	pll v;
	fore(i,0,n-1){
		fore(u,0,n){
			fore(j,0,SZ(adj[u])){
				v=adj[u][j];
				dist[v.fst] = min(dist[v.fst],dist[u]+v.snd);
			}
		}
	}
}

bool cycle(){
	pll v; 
	fore(i,0,n-1){
		fore(u,0,n){
			fore(j,0,SZ(adj[u])){
				v = adj[u][j];
				if((dist[u]+v.snd)<dist[v.fst]) return 1;
			}
		}
	}
	return 0;
}

int main(){FIN
	ll t;
	ll a,b,c;

	cin >> t;
	while(t--){
		cin >> n >> m;
		
		adj.assign(n,vpll());
		
		fore(i,0,m){
			cin >> a >> b >> c;
			adj[a].pb({b,c});
		}
		
		dist.assign(n,1e9);

		bford(0);
		if(cycle()) cout << "possible\n";
		else cout << "not possible\n";

	}
	return 0;
}
