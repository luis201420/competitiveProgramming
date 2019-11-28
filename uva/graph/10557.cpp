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
typedef vector<vll> vvll;
typedef vector<bool> vbool;

vvll adj;
vll energy,dist;
ll n;
vbool visited;

void bford(){
	dist[0]=100;
	ll v;
	fore(i,0,n-1){
		fore(u,0,n){
			fore(j,0,SZ(adj[u])){
				v=adj[u][j];
				if((dist[u]+energy[v])>0)
					dist[v]=max(dist[v],dist[u]+energy[v]);
			}
		}
	}
}

bool isPath( ll x){
	visited[x]=1;
	ll v;
	fore(i,0,SZ(adj[x])){
		v=adj[x][i];
		if(v == n-1) return 1;
		if(!visited[v] && isPath(v)) return 1;
	}
	return 0;
}

int main(){FIN
	
	ll e,m,v;

	while(cin >> n){
		if(n==-1) break;

		adj.assign(n,vll());
		energy.resize(n);

		fore(i,0,n){
			cin >> e >> m;
			energy[i]=e;
			fore(j,0,m){
				cin >> v;
				adj[i].pb(v-1);
			}
		}

		dist.assign(n,-1e6);
		bford();

		bool cycle = 0;

		fore(u,0,n){
			fore(j,0,SZ(adj[u])){
				v=adj[u][j];
				if(dist[v]<(dist[u]+energy[v]) && (dist[u]+energy[v])>0){
					visited.assign(n,0);
					if(isPath(u)){
						cycle=1;
						break;
					}
				}
			}
		}

		if(dist[n-1]>0 || cycle) cout << "winnable";
		else cout << "hopeless";
		cout << "\n";
	}
	return 0;
}
