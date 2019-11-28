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
ll ans;

vll links, sizes;

ll findU(ll x){
	if(x == links[x]) return x;
	return links[x] = findU(links[x]);
}

bool same(ll x,ll y){
	return findU(x)==findU(y);
}

void unite(ll x, ll y){
	x = findU(x);
	y = findU(y);
	if(sizes[x]<sizes[y])swap(x,y);
	sizes[x]+=sizes[y];
	links[y]=x;
}

bool myComp(const Edge &e1, const Edge &e2){
	return e1.w < e2.w;
}

void MST(){
	sort(ALL(edges),myComp);
	for(Edge it:edges){
		if(!same(it.u,it.v)){
			unite(it.u,it.v);
			ans+=it.w;
		}
	}
}

int main(){FIN
	
	ll t,n,m,c,contID;
	string a,b;
	map<string,ll> ids;

	cin >> t;

	fore(tt,0,t){
		
		if(tt)cout << "\n";
		cin >> n >> m;
		
		contID=1;
		fore(i,0,m){
			cin >> a >> b >> c;
			if(ids[a]==0)ids[a] = contID++;
			if(ids[b]==0)ids[b] = contID++;
			edges.pb({ids[a]-1,ids[b]-1,c});
		}
		
		//DBG(contID);
		
		ans = 0;
		sizes.assign(n,1);
		fore(i,0,n)links.pb(i);

		MST();
		cout << ans << "\n";

		links.clear();
		ids.clear();
		edges.clear();
	}
	return 0;
}
