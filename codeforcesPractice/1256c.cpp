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
	ll n,m,d,w;
	vll ms,ans,res;

	cin >> n >> m >> d;
	ms.resize(m);
	fore(i,0,m) cin >> ms[i];
	
	w = 0;
	fore(i,0,m){
		fore(j,0,d-1) ans.pb(0);
		fore(j,0,ms[w]) ans.pb(w+1);
		w++;
	}
	fore(i,0,d-1) ans.pb(0);
	if(SZ(ans)<n) cout << "NO\n";
	else{
		ll aux = SZ(ans)-n;
		fore(i,0,SZ(ans)){
			if(ans[i] == 0 && aux) aux--;
			else res.pb(ans[i]);
		}
		cout << "YES\n";
		fore(i,0,SZ(res)){
			if(i) cout << " ";
			cout << res[i];
		}
		cout << "\n";
	}
	return 0;
}
