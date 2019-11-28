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
vbool visited;
vll color;

bool dfs(ll r, int c){
	visited[r]=1;
	bool v;
	if(color[r]!=-1 && color[r]!=c) v=0;
	else {
		v=1;
		color[r]=c;
	}
	fore(i,0,SZ(adj[r])){
		if(!visited[adj[r][i]])
			v&=dfs(adj[r][i],(c+1)%2);
		else
			v&=(color[adj[r][i]]==(c+1)%2);
	}
	return v;
}

int main(){FIN
	ll n,m,a,b;

	cin >> n >> m;
	
	adj.assign(n,vll());
	visited.assign(n,0);
	color.assign(n,-1);

	while(m--){
		cin >> a >> b;
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
	}
	ll c1 = 0,c2 = 0;
	fore(i,0,n){
		if(!visited[i]){
			if(dfs(i,0))c1++;
			else c2++;
		}
	}
	DBG(c1);DBG(c2);
	cout << c1+max(c2-1,0ll) << "\n";
	return 0;
}
