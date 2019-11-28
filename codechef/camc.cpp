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
	
	ll t,n,m,ans;
	vpll ns;
	map<ll,ll> cont;

	cin >> t;
	while(t--){
		cin >> n >> m;
		ns.resize(n);

		fore(i,0,n){
			cin >> ns[i].fst;
			ns[i].snd = (i%m);
		}

		sort(ALL(ns));
			
		ans = 1e9;
		ll x,y,v=0;
		x = y = 0;

		while(x<n){	
			if(cont[ns[y].snd]==0){
				v++;
			}
			cont[ns[y].snd]++;
			while(v==m){
				ans = min(ans,ns[y].fst-ns[x].fst);
				cont[ns[x].snd]--;
				if(cont[ns[x].snd]==0) v--;
				x++;
			}
			y++;
			if(y>=n) break;
		}
		cout << ans << "\n";
		cont.clear();
	}
	return 0;
}
