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
vll dfs_num,dfs_low,ans;
vbool visited;
ll numSCC,dfsCounter;
stack<ll> S;

void tarjan(ll u){
	dfs_low[u] = dfs_num[u] = dfsCounter++;
	S.push(u);
	visited[u]=1;
	ll v;
	fore(i,0,SZ(adj[u])){
		v = adj[u][i];
		if(dfs_num[v]==-1) 
			tarjan(v);
		if(visited[v])
			dfs_low[u]=min(dfs_low[u],dfs_low[v]);
	}
	if(dfs_low[u]==dfs_num[u]){
		while(1){
			v = S.top(); S.pop();
			visited[v]=0;
			ans[v]=numSCC;
			if(u==v)break;
		}
		numSCC++;
	}
}

int main(){FIN

	ll n,k;
	vll p;

	cin >> n >> k;

	adj.assign(n,vll());
	
	ll ant,ac;
	fore(i,0,n){
		cin >> ac;
		p.pb(ac);
		if(i) adj[ant-1].pb(ac-1);
		ant = ac;
	}

	fore(i,0,n){
		cin >> ac;
		if(i) adj[ant-1].pb(ac-1);
		ant = ac;
	}

	ans.resize(n);

	dfs_num.assign(n,-1);dfs_low.assign(n,0);visited.assign(n,0);
	dfsCounter = numSCC = 0;
	fore(i,0,n){
		if(dfs_num[i]==-1)
			tarjan(i);
	}
	if(numSCC < k) cout <<"NO\n";
	else{
		cout << "YES\n";
		string mask = string(numSCC,'-');
		char aux = 'a';
		fore(i,0,n){
			p[i]--;
			if(mask[ans[p[i]]]=='-'){
				mask[ans[p[i]]]=aux;
				aux = min('z',char(aux+1));
			}
		}
		fore(i,0,n){
			cout << mask[ans[i]];
		}
		cout << "\n";
	}
	return 0;
}
