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

vll ns;
ll n;

ll solve(ll c){
	DBG(c);
	if(c <= 0) return 0;
	ll a,v1,v2,ans=1e9,p1,p2;
	fore(i,1,n){
		if(ns[i]!=ns[i-1]){
			a = ns[i];
			p1 = p2 = 0;
			if((i+1)<n){
				//p1 = (ns[i]==ns[i+1]);
				p2 = (ns[i-1]==ns[i+1]);
			}
			ns[i]=ns[i-1];
			v1 = 1 + solve(c-(1+p2)+p1);
			ns[i]=a;
			p1 = p2 = 0;
			a = ns[i-1];
			if((i-2)>=0){
				//p1 = (ns[i-1]==ns[i-2]);
				p2 = (ns[i]==ns[i-2]);
			}
			ns[i-1]=ns[i];
			v2 = 1 + solve(c-(1+p2)+p1);
			ns[i-1]=a;
			ans = min(ans, min(v1,v2));
		}
	}
	return ans;
}

int main(){FIN
	ll t,k,ans,cont;

	cin >> t;
	fore(tt,1,t+1){
		cin >> n >> k;

		ns.resize(n);
		fore(i,0,n) cin >> ns[i];
		cont = 0;
		fore(i,1,n) cont += (ns[i]!=ns[i-1]);
		cout <<"Case #" << tt << ": ";
		if(cont <= k) cout << 0 << "\n";
		else{
			ans = solve(cont-k);
			cout << ans << "\n";
		}
	}
	return 0;
}
