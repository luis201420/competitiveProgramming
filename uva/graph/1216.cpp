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
typedef pair<double,double> pdd;
typedef vector<pdd> vpdd;
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
	if(sizes[x]<sizes[y]) swap(x,y);
	sizes[x]+=sizes[y];
	links[y]=x;
}

struct Edge{
	ll u,v;
	double w;
};

vector<Edge> edges;
ll k;
double ans;

bool myComp(const Edge &e1, const Edge &e2){
	return e1.w < e2.w;
}

void MST(ll c){
	sort(ALL(edges),myComp);
	for(Edge it:edges){
		if(!same(it.u,it.v)){
			unite(it.u,it.v);
			ans=max(ans,it.w);
			c--;
		}
		if(c==k)break;
	}
}

double dist(const pdd &p1, const pdd &p2){
	double dx = abs(p1.fst-p2.fst);
	double dy = abs(p1.snd-p2.snd);
	return sqrt((dx*dx)+(dy*dy));
}

int main(){FIN
	
	ll t,cont;
	pdd xy;
	double x,y;
	vpdd points;

	cin >> t;
	while(t--){

		cin >> k;
		cont=0;

		while(cin >> x){
			if(x==-1)break;
			cin >> y;
			xy = {x,y};
			fore(i,0,SZ(points)){
				edges.pb({cont,i,dist(xy,points[i])});
			}
			points.pb(xy);
			cont++;
		}
		
		sizes.assign(cont,1);
		fore(i,0,cont) links.pb(i);
		
		ans=-1e9;
		MST(cont);

		cout << ll(ceil(ans)) << "\n";
		
		links.clear();
		points.clear();
		edges.clear();
	}

	return 0;
}
