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
	ll n,m,v,q,L,U,ans,p1,p2;
	vvll diag;

	while(cin >> n >> m && n && m){
		
		diag.assign(n+m-1,vll());

		fore(i,0,n){
			fore(j,0,m){
				cin >> v;
				diag[(j-i)+(n-1)].pb(v);
			}
		}
		cin >> q;
		while(q--){
			cin >> L >> U;
			ans = 0;
			fore(i,0,SZ(diag)){
				p1 = lower_bound(ALL(diag[i]),L)-diag[i].begin();
				p2 = lower_bound(ALL(diag[i]),U+1)-diag[i].begin();
				ans = max(ans,p2-p1);
			}
			cout << ans << "\n";
		}
		cout << "-\n";
	}	
	return 0;
}
