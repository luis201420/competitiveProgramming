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

const ll match = 0;
const ll miss = -1;

inline ll score(const char &a, const char &b){
	if(a==b) return match;
	else return miss;
}

int main(){FIN


	vvll dp;
	ll n,m;
	ll x,y,cont,tt=0;

	string s,t;
	while(getline(cin,s)){

		if(tt) cout << "\n";
		tt++;
		getline(cin,t);

		n = SZ(s);
		m = SZ(t);

		dp.assign(n+1,vll(m+1,0));
		
		fore(i,0,n+1)
			dp[i][0]=i*miss;
		fore(j,0,m+1)
			dp[0][j]=j*miss;

		fore(i,1,n+1){
			fore(j,1,m+1){
				dp[i][j]=max(dp[i-1][j-1]+score(s[i-1],t[j-1]),max(dp[i-1][j]+miss,dp[i][j-1]+miss));
			}
		}
		
		
		cout << -dp[n][m] << "\n";
		
		x = n;y=m;

		cont = 1;

		while(x+y){
			if(x>0 && y>0 &&(dp[x-1][y-1]+score(s[x-1],t[y-1])) == dp[x][y]){
				if(score(s[x-1],t[y-1])<0)
					cout <<cont++<< " Replace " << x << "," << t[y-1] << "\n";
				x--;y--;
			}
			else if( x>0 &&(dp[x-1][y]+miss) == dp[x][y]){
				cout << cont++ <<  " Delete " << x << "\n";
				x--;
			}
			else{
				cout << cont++ << " Insert " << x+1 << "," << t[y-1] << "\n";
				y--;
			}
		}

	}

	return 0;
}
