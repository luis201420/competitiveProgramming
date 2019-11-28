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
	ll t,n,k,v,c;
	string s,ans;
	vll ones;

	cin >> t;

	while(t--){
		cin >> n >> k;
		cin >> s;
		c=0;
		fore(i,0,n){
			if(s[i]=='1')c++;
			else ones.pb(c);
		}
		ans = "";
		c=0;
		fore(i,0,SZ(ones)){
			v = ones[i]-c;
			if(v<=k){
				ans+="0";
				k-=v;
			}
			else{
				ans+=string(v-k,'1');
				c+=v-k;
				ans+="0";
				k=0;
			}
		}
		ans += string(n-SZ(ans),'1');
		cout << ans << "\n";
		ones.clear();
	}
	return 0;
}
