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

vll ones;

void sumT(){
	fore(i,1,SZ(ones)) ones[i] += ones[i-1];
}

ll rmq(ll L, ll R){
	return ones[R]-(L?ones[L-1]:0);
}

int main(){FIN
	ll n,q,ans,cpos,lones,a,b;
	vpll ps;
	vll cont;

	cin >> n >> q;
	cont.assign(n,0);
	fore(i,0,q){
		cin >> a >> b;
		ps.pb({a-1,b-1});
		fore(j,a-1,b) cont[j]++;
	}

	ans = 0;
	fore(i,0,q){
		cpos = 0;
		ones.assign(n,0);
		fore(j,ps[i].fst,ps[i].snd+1) cont[j]--;
		
		fore(j,0,n){
			if(cont[j]>0) cpos++;
			if(cont[j]==1) ones[j]++;
		}
		sumT();
		fore(j,i+1,q){
			lones = rmq(ps[j].fst,ps[j].snd);
			ans = max(ans, cpos-lones);
		}

		fore(j,ps[i].fst,ps[i].snd+1) cont[j]++;
	}
	cout << ans << "\n";
	return 0;
}
