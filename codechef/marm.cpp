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
	ll t,n,k,mm;
	ll ns[10010];
	vll ans,res;
	ll x,y;

	cin >> t;

	while(t--){
		
		cin >> n >> k;
		fore(i,0,n) cin >> ns[i];
		
		if(n&1){
			mm = ns[n/2];
			ns[n/2] = 0;
		}
		x = 0, y = n-1;
		
		while(x<=y){
			ans.pb(ns[x]^ns[y]);
			x++;
			y--;
		}

		while(y>=0){
			ans.pb(ns[y]);
			y--;
		}

		y=n-1;
		x-=(1+(n&1));
		
		while(y>x){
			ans.pb(ns[y]);
			y--;
		}

		x=(n/2)-1;
		while(x>=0){
			ans.pb(ans[x]);
			x--;
		}
		
		fore(i,0,n) ans.pb(ns[i]);
		
		res.resize(n);
		
		if(k<n){
			fore(i,0,n)res[i]=ns[i];
			if(n&1)res[n/2]=mm;
			fore(i,0,k) res[i]=ans[i];
		}
		else{
			k=(k%(3*n));
			x = (k+(3*n)-n)%(3*n);
			fore(i,0,n) res[(x+i)%n] = ans[(x+i)%(3*n)];
		}
		
		
		fore(i,0,n) {
			if(i) cout << " ";
			cout << res[i];
		}
		cout << "\n";
		ans.clear();
		res.clear();
	}
	return 0;
}
