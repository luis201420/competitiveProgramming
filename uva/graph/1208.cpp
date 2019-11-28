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

vll links,sizes;

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

bool myComp(const Edge &e1, const Edge &e2){
	return e1.w < e2.w;
}

void MST(){
	stable_sort(ALL(edges),myComp);
	for(Edge it:edges){
		if(!same(it.u,it.v)){
			unite(it.u,it.v);
			cout << char('A'+it.u) << "-" << char('A'+it.v) << " " << it.w << "\n";
		}
	}
}

int main(){FIN
	
	ll t,n,b,c;
	string line,s;

	cin >> t;
	
	fore(tt,0,t){

		cin >> n;
		getline(cin,line);
		fore(i,0,n){
			getline(cin,line);
			s = "";
			b =  0;
			fore(j,0,SZ(line)){
				if(line[j]==' ')continue;
				else if(line[j]==','){
					c = stoll(s.c_str());
					if(c>0)edges.pb({i,b,c});
					b++;
					s="";
				}
				else s+=line[j];
			}
			c = stoll(s.c_str());
			if(c>0)edges.pb({i,b,c});
			s="";
		}
		sizes.assign(n,1);
		fore(i,0,n) links.pb(i);
		
		cout << "Case " << tt+1 << ":\n";
		MST();

		edges.clear();
		links.clear();

	}
	return 0;
}
