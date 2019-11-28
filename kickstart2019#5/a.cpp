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

vll links, sizes;

ll findU(ll x){
	if(x == links[x]) return x;
	return links[x] = findU(links[x]);
}

bool same(ll x, ll y){
	return findU(x)==findU(y);
}

void unite(ll x, ll y){
	x = findU(x);
	y = findU(y);
	if(sizes[x]<sizes[y]) swap(x,y);
	sizes[x]+=sizes[y];
	links[y]=x;
}

struct Edge{
	ll u,v,w;
};

vector<Edge> edges;
ll ans,cc;

void MST(){
	for(Edge e:edges){
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			ans+=e.w;
			cc--;
		}
	}
}

int main(){FIN
	

	ll t,n,m,a,b,test=1;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		while(m--){
			cin >> a >> b;
			edges.pb({a-1,b-1,1});
		}
		cc = n;

		sizes.assign(n,1);
		fore(i,0,n)links.pb(i);
		
		ans=0;
		MST();
		cout << "Case #" << test++ << ": ";
		cout << ans + (cc-1)*2 << "\n";
		
		edges.clear();
		links.clear();
	}
	return 0;
}
