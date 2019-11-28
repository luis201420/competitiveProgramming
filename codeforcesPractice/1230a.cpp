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
	vll ns(4);
	ll c1,c2;
	bool ver;

	fore(i,0,4) cin >>ns[i];

	ver = 0;
	fore(i,0,(1<<3)){
		c1 = c2 = 0;
		fore(j,0,4){
			if(i&(1<<j))c1+=ns[j];
			else c2+=ns[j];
		}
		if(c1 == c2)ver=1;
	}
	if(ver) cout << "YES\n";
	else cout <<"NO\n";
	return 0;
}
