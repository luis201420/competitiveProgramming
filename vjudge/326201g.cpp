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

vll d;

ll precalcule(){
	d.assign(1000001,0);
	ll p = 1;
	while(p < 1000001){
		for(ll j=p;j<1000001;j+=p) d[j]++;
		p++;
	}
}

int main(){FIN
	ll a,b,c,ans;

	precalcule();
	
	cin >> a >> b >> c;

	ans = 0;
	fore(i,1,a+1){
		fore(j,1,b+1){
			fore(k,1,c+1){
				ans+=(d[i*j*k]%1073741824);
			}
		}
	}
	cout << ans << "\n";

	return 0;
}
