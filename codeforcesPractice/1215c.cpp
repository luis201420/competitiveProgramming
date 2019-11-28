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
	ll n,contA,contB;
	string s,t;
	vll as,bs;
	vpll ans;

	cin >> n;
	cin >> s >> t;

	contA = contB = 0;
	fore(i,0,n){
		if(s[i]=='a')contA++;
		else contB++;
		if(t[i]=='a')contA++;
		else contB++;
	}
	if(contA&1 || contB&1) cout << -1 << "\n";
	else{
		fore(i,0,n){
			if(s[i]!=t[i]){
				if(s[i]=='a')bs.pb(i);
				else as.pb(i);
			}
		}
		if((SZ(bs)&1 && !SZ(as)&1) || (SZ(as)&1 && !SZ(bs)&1)){
			cout << "-1\n";
		}
		else{
			fore(i,0,SZ(as)-1){
				ans.pb({as[i]+1,as[i+1]+1});
				i++;
			}
			if(SZ(as)&1){
				ans.pb({as[SZ(as)-1]+1,as[SZ(as)-1]+1});
				bs.pb(as[SZ(as)-1]);
			}
			fore(i,0,SZ(bs)-1){
				ans.pb({bs[i]+1,bs[i+1]+1});
				i++;
			}
			cout << SZ(ans) << "\n";
			fore(i,0,SZ(ans)){
				cout << ans[i].fst << " " << ans[i].snd << "\n";
			}
		}
	}
	return 0;
}
