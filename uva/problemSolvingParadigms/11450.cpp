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

ll m,c;
ll dp[210][25];
vvll models;

ll solve(ll money,ll g){
	if(money < 0) return -1e9;
	if(g == c) return m-money;
	
	ll & res = dp[money][g];
	if(res != -1) return res;
	
	fore(i,0,SZ(models[g])){
		res = max(res, solve(money-models[g][i], g + 1));
	}
	return res;
}

int main(){FIN
	ll t,k,ans;

	cin >> t;
	while(t--){
		cin >> m >> c;
		
		memset(dp,-1,sizeof(dp));
		
		models.assign(c,vll());
		fore(i,0,c){
			cin >> k;
			models[i].assign(k,0);
			fore(j,0,k) cin >> models[i][j];
		}
		ans = solve(m,0);
		if(ans < 0) cout << "no solution\n";
		else cout << ans << "\n";
	}
	return 0;
}
