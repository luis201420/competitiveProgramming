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
	if(sizes[x]<sizes[y])swap(x,y);
	sizes[x]+=sizes[y];
	links[y]=x;
}

struct Edge{
	ll u,v,w;
};

vector<Edge> edges;
ll mst;
bool zero;

bool mycomp(const Edge &e1, const Edge &e2){
	return e1.w<e2.w;
}

void MST(){
	sort(ALL(edges),mycomp);
	for(Edge it:edges){
		if(!same(it.u,it.v)){
			if(zero ||(it.u!=0 && it.v)){
				if(it.u == 0 || it.v == 0)zero=0;
				unite(it.u,it.v);
				mst+=it.w;
			}
		}
	}
}

ll dist(const string &x, const string &y){
	ll d=0,v1,v2;
	fore(i,0,4){
		v1 = x[i]-'0';
		v2 = y[i]-'0';
		if(v1<v2) swap(v1,v2);
		d+=min( (v1-v2) , ((v2+10)-v1) );
	}
	return d;
}

int main(){FIN
	
	ll t,n,c;
	string s;
	vstr keys;

	cin >> t;
	while(t--){
		cin >> n;
		keys.pb("0000");
		n++;
		fore(i,1,n){
			cin >> s;
			fore(j,0,SZ(keys)){
				c=dist(keys[j],s);
				edges.pb({i,j,c});
			}
			keys.pb(s);
		}
		sizes.assign(n,1);
		fore(i,0,n)links.pb(i);
		mst=0;zero=1;
		MST();
		cout << mst <<"\n";
		links.clear();
		keys.clear();
		edges.clear();
	}
	return 0;
}
