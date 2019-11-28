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
	ll n,x,y;
	vpll ps;
	cin >> n;

	while(n--){
		cin >> x >> y;
		ps.pb({x,y});
	}
	n = SZ(ps);
	sort(ALL(ps));
	map<pll,ll> cont;
	fore(i,0,n){
		fore(j,i+1,n){
			cont[{ps[j].fst-ps[i].fst,ps[j].snd-ps[i].snd}]++;
		}
	}
	vll ans;
	for(auto it:cont){
		ans.pb(it.snd);
	}
	
	sort(ALL(ans),greater<ll>());
	//ans.erase(unique(ALL(ans)),ans.end());	
	
	ll c = 0;
	ll m = (n+1)/2;
	
	fore(i,0,SZ(ans)){
		if(ans[i]<m)break;
		c++;
	}

	cout << c*2 << "\n";
	return 0;
}
