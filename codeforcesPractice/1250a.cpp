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

int main(){FIN
	ll n,m,v,a,ax;
	vll ns,ps;
	vpll ans;

	cin >> n >> m;
	
	fore(i,0,n){
		ns.pb(i);
		ps.pb(i);
		ans.pb({i,i}); //min,max
	} 

	fore(i,0,m){
		cin >> v;
		v--;
		a=ps[v]-1;
		if(a>=0){
			ax=ns[a];
			swap(ps[ns[a]],ps[v]);
			swap(ns[ps[ns[a]]],ns[ps[v]]);
			ans[ax]={min(ans[ax].fst,ps[ax]),max(ans[ax].snd,ps[ax])};
			ans[v]={min(ans[v].fst,ps[v]),max(ans[v].snd,ps[v])};
		}
	}

	fore(i,0,n){
		cout << ans[i].fst+1 << " " << ans[i].snd+1 << "\n";
	}
	return 0;
}
