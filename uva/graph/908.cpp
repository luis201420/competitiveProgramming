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

struct Edge{
	ll u,v,w;
};

vector<Edge> edges;
ll ans2;

vll links,sizes;

ll findU(ll x){
	if(x == links[x]) return x;
	return links[x] = findU(links[x]);
}

bool same(ll x, ll y){
	return findU(x) == findU(y);
}

void unite(ll a, ll b){
	a = findU(a);
	b = findU(b);
	if(sizes[a]<sizes[b]) swap(a,b);
	sizes[a]+=sizes[b];
	links[b]=a;
}

bool myComp(Edge & e1, Edge & e2){
	return e1.w < e2.w;
}

void MST(){
	sort(ALL(edges),myComp);
	for(Edge it:edges){
		if(!same(it.u,it.v)){
			unite(it.u,it.v);
			ans2+=it.w;
		}
	}
}

int main(){FIN

	ll n,a,b,c,ans1,k,m,cont=0;
	
	while(cin >> n){
		
		if(cont) cout << "\n";
		cont++;
		ans1=0;

		fore(i,0,n-1){
			cin >> a >> b >> c;
			ans1+=c;
		}
		cin >> k;
		fore(i,0,k){
			cin >> a >> b >> c;
			edges.pb({a-1,b-1,c});
		}
		cin >> m;
		fore(i,0,m){
			cin >> a >> b >> c;
			edges.pb({a-1,b-1,c});
		}
		
		sizes.assign(SZ(edges),1);
		fore(i,0,SZ(edges))links.pb(i);
		
		ans2=0;
		MST();
	
		links.clear();
		edges.clear();

		cout << ans1 << "\n";
		cout << ans2 << "\n";
	}
	return 0;
}
