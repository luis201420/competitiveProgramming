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

ll n;
vll ns,lis,lds,dp;

ll solve(){

	lis.resize(n);	
	lis[0] = 1;
	fore(i,1,n){
		lis[i]=1;
		fore(j,0,i){
			if(ns[i] > ns[j] && lis[i] < (lis[j]+1))lis[i]=lis[j]+1;
		}
	}

	
	lds.resize(n);
	lds[0] = 1;
	fore(i,1,n){
		lds[i]=1;
		fore(j,0,i){
			if(ns[i] < ns[j] && lds[i] < (lds[j]+1))lds[i]=lds[j]+1;
		}
	}

	ll ans = 0;
	fore(i,0,n){
		ans = max(ans, lis[i]+lds[i]-1);
	}
	return ans;
}


int main(){FIN
	ll t;

	cin >> t;
	while(t--){
		cin >> n;
		ns.resize(n);
		fore(i,0,n) cin >> ns[i];
		reverse(ALL(ns));
		cout << solve() << "\n";
	}
	return 0;
}
