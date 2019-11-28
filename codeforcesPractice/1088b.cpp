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
	ll n,k,ac;
	vll ns;

	cin >> n >> k;
	ns.resize(n);
	fore(i,0,n) cin >> ns[i];
	sort(ALL(ns));
	ac=0;
	fore(i,0,n){
		if(k<=0) break;
		if((ns[i]-ac)==0)continue;
		else{
			k--;
			cout << ns[i]-ac << "\n";
			ac+=(ns[i]-ac);
		}
	}
	fore(i,0,k) cout << "0\n";
	return 0;
}
