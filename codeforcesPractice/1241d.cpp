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
	ll t,n,ans,mm;
	vll l,r,dp,ns;

	cin >> t;
	while(t--){
		cin >> n;
		
		dp.assign(n+1,0);
		l.assign(n+1,1e9);
		r.assign(n+1,-1e9);

		ns.resize(n);

		fore(i,0,n){
			cin >> ns[i];
			l[ns[i]]=min(l[ns[i]],ll(i));
			r[ns[i]]=max(r[ns[i]],ll(i));
		}

		sort(ALL(ns));
		ns.erase(unique(ALL(ns)),ns.end());
		reverse(ALL(ns));

		mm = 1;
		ans = n;
		dp[0]=1;
		fore(i,1,SZ(ns)){
			if(r[ns[i]] < l[ns[i-1]]) dp[i] = dp[i-1]+1;
			else dp[i]=1;
			mm = max(mm,dp[i]);
		}
		cout << SZ(ns)-mm << "\n";
	}
	return 0;
}
