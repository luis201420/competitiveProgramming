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
typedef pair<double,double> pdd;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef pair<int,int> pii;
typedef vector<string> vstr;

vll links,sizes;

ll findU(ll x){
	if(x == links[x]) return x;
	return links[x] = findU(links[x]);
}

bool same(ll x, ll y){
	return findU(x) == findU(y);
}

void unite(ll x, ll y){
	x = findU(x);
	y = findU(y);
	if(sizes[x] < sizes[y]) swap(x,y);
	sizes[x]+=sizes[y];
	links[y]=x;
}

struct Edge{
	ll u,v;
	double w;
};

vector<Edge> edges;

bool myComp(const Edge &e1, const Edge &e2){
	return e1.w < e2.w;
}

vpll ans;

void MST(){
	sort(ALL(edges),myComp);
	for(Edge it:edges){
		if(!same(it.u,it.v)){
			unite(it.u,it.v);
			ans.pb({it.u,it.v});
		}
	}
}

double dist(const pdd &a,const pdd &b){
	double dx = abs(a.fst-b.fst);
       	double dy = abs(a.snd-b.snd);
	return (dx*dx)+(dy*dy);
}

int main(){FIN
	ll t,n,m,t1,t2;
	pdd xy;
	vpdd towns;

	cin >> t;

	ll test = 0;
	while(t--){

		if(test) cout << "\n";
		test++;
		cin >> n;
		fore(i,0,n){
			cin >> xy.fst >> xy.snd;
			fore(j,0,SZ(towns)){
				edges.pb({j,i,dist(towns[j],xy)});
			}
			towns.pb(xy);
		}

		sizes.assign(n,1);
		fore(i,0,n) links.pb(i);

		cin >> m;
		fore(i,0,m){
			cin >> t1 >> t2;
			t1--;t2--;
			if(!same(t1,t2)) unite(t1,t2);
		}

		MST();
		
		if(SZ(ans)){
			fore(i,0,SZ(ans)){
				cout << ans[i].fst+1 << " " << ans[i].snd+1 << "\n";
			}
		}
		else cout << "No new highways need\n";
		
		ans.clear();
		towns.clear();
		links.clear();
		edges.clear();
	}
	return 0;
}
