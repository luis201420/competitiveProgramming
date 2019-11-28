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

ll gcd (ll a, ll b) {
	while (b) {
        	a %= b;
        	swap(a, b);
    	}
    	return a;
}

int main(){FIN
	ll A,B,v;
	set<ll> d;
	vll ans;
	bool ver;

	cin >> A >> B;
	
	v = gcd(A,B);
	
	fore(i,1,sqrt(v)+1){
		if((v%i) == 0){
			d.insert(i);
			d.insert(v/i);
		}
	}

	for(ll x:d){

		ver=1;
		fore(j,1,SZ(ans)){
			if(x%ans[j]==0){
				ver=0;
				break;
			}
		}
		if(ver) ans.pb(x);
	}

	cout << SZ(ans) << "\n";
	return 0;
}
