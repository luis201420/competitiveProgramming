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

ll findU(ll x){
	if(x==links[x]) return x;
	return links[x] = findU(links[x]);
}

bool same(ll x, ll y){
	return findU(x) == findU(y);
}

void unite(ll x, ll y){
	x=findU(x);
	y=findU(y);
	if(sizes[x]<sizes[y])swap(x,y);
	links[y]=x;
	sizes[x]+=sizes[y];
}

int main(){FIN
	ll t,n,v;

	cin >> t;
	while(t--){
		cin >> n;
		sizes.assign(n,1);
		fore(i,0,n) links.pb(i);
		fore(i,0,n){
			cin >> v;
			v--;
			if(!same(i,v))unite(i,v);
		}
		fore(i,0,n){
			if(i) cout << " ";
			cout << sizes[findU(i)];
		}
		cout << "\n";
		links.clear();
	}
	return 0;
}
