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

vll links,sizes;
ll numPair;

ll findU(ll x){
	if(x == links[x])return x;
	return links[x] = findU(links[x]);
}

void unite(ll x, ll y){
	x = findU(x);
	y = findU(y);
	if(sizes[x]<sizes[y])swap(x,y);
	numPair+=(sizes[x]*sizes[y]);
	sizes[x]+=sizes[y];
	links[y]=x;
}

struct Edge{
	ll u,v,w;
};

bool myComp(const Edge &e1, const Edge &e2){
	return e1.w < e2.w;
}

vector<Edge> edges;
vpll qs;
vll ans;

void mst(){

	sort(ALL(qs));
	sort(ALL(edges),myComp);
	
	ll j = 0;
	numPair = 0;
	
	fore(i,0,SZ(qs)){
		while(j<SZ(edges) && edges[j].w <= qs[i].fst){
			unite(edges[j].u,edges[j].v);
			j++;
		}
		ans[qs[i].snd]=numPair;
	}
}

int main(){FIN

	ll n,m;
	ll a,b,c;

	cin >> n >> m;
	fore(i,0,n-1){
		cin >> a >> b >> c;
		a--;b--;
		edges.pb({a,b,c});
	}

	ans.resize(m);
	qs.assign(m,pll());
	
	fore(i,0,m){
		cin >> a;
		qs[i].fst = a;
		qs[i].snd = i;
	}
	sizes.assign(n,1);
	fore(i,0,n)links.pb(i);
	mst();
	
	fore(i,0,m){
		if(i) cout << " ";
		cout << ans[i];
	}
	cout << "\n";
	return 0;
}
