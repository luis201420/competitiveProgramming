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

	string s,t;
	ll n,m,cont=1;
	vvll dp;

	while(getline(cin,s)){
		if(s=="#")break;
		getline(cin,t);
		
		n=SZ(s);
		m=SZ(t);

		dp.assign(n+1,vll(m+1,0));

		fore(i,0,n+1)
			dp[i][0]=0;
		fore(j,0,m+1)
			dp[0][j]=0;

		fore(i,1,n+1)
			fore(j,1,m+1)
				dp[i][j]=max(dp[i-1][j-1]+(s[i-1]==t[j-1]),max(dp[i-1][j],dp[i][j-1]));

		cout << "Case #" << cont++ << ": you can visit at most " << dp[n][m] << " cities.\n";
	}
	return 0;
}
