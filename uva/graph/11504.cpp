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

vector<vll> AdjList,inEdge;
vll dfs_num, dfs_low;
stack<ll> S;
vector<bool> visited;
ll dfsCount, nSCC;

void tarjanSCC(ll u){
	dfs_num[u] = dfs_low[u] = dfsCount++;
	S.push(u);
	visited[u]=1;
	ll v;
	fore(i,0,SZ(AdjList[u])){
		v = AdjList[u][i];
		if(dfs_num[v] == -1)
			tarjanSCC(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
	}
	if(dfs_low[u] == dfs_num[u]){
		vll a,b;
		while(1){
			v = S.top(); S.pop();
			a.pb(v);
			fore(i,0,SZ(inEdge[v])) b.pb(inEdge[v][i]);
			visited[v]=0;
			if(u==v) break;
		}
		sort(ALL(b));
		b.erase(unique(ALL(b)),b.end());
		sort(ALL(a));
		a.erase(unique(ALL(a)),a.end());
		if(SZ(a)==1 && SZ(b)==0){
			nSCC++;
			return;
		}
		if(SZ(a)==SZ(b)){
			bool ver=1;
			fore(i,0,SZ(a)){
				if(a[i]!=b[i]){ver=0;break;}
			}
			nSCC+=(ver);
		}
	}
}

int main(){FIN
	ll t,n,m,a,b;
	cin >> t;
	while(t--){
		cin >> n >> m;
		AdjList.assign(n,vll());
		inEdge.assign(n,vll());
		while(m--){
			cin >> a >> b;
			AdjList[a-1].pb(b-1);
			inEdge[b-1].pb(a-1);
		}
		dfs_num.assign(n,-1); dfs_low.assign(n,0);
		visited.assign(n,0);
		dfsCount = nSCC = 0;
		fore(i,0,n){
			if(dfs_num[i]==-1)
				tarjanSCC(i);
			//DBG(dfs_num[i]);
			//DBG(dfs_low[i]);
		}
		cout << nSCC << "\n";
	}
	return 0;
}
