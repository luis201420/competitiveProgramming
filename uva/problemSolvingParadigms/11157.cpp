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

	ll t,n,d,dist,L,R,ans;
	char op,ig;
	vll stone;

	cin >> t;
	fore(tt,1,t+1){
		cin >> n >> d;
		
		stone.pb(0);stone.pb(0);
		stone.pb(d);stone.pb(d);

		fore(i,0,n){
			cin >> op >> ig >> dist;
			stone.pb(dist);
			if(op == 'B') stone.pb(dist);
		}
		sort(ALL(stone));
		ans = 0;
		fore(i,2,SZ(stone)){
			ans = max(ans,stone[i]-stone[i-2]);
		}
		fore(i,3,SZ(stone)){
			ans = max(ans,stone[i]-stone[i-2]);
		}
		cout << "Case " << tt << ": " << ans << "\n";
		stone.clear();
	}
	return 0;
}
