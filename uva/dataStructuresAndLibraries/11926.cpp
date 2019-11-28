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

bitset<1000001> bs;

int main(){FIN
	ll n, m;
	ll a,b,r;
	bool ver;

	while(cin >> n >> m && (n || m)){
		
		ver=1;

		fore(i,0,n){
			cin >> a >> b;
			if(ver){
				fore(j,a,b){
					if(bs.test(j)){
						ver = 0;
						break;
					}
					bs.set(j);
				}
			}
		}
		fore(i,0,m){
			cin >> a >> b >> r;
			if(ver){
				while(1){
					fore(j,a,b){
						if(bs.test(j)){
							ver=0;
							break;
						}
						bs.set(j);
					}
					a += r;
					b += r;
					if(a>1000000 && b > 1000000)break;
					if(b>1000000) b = 1000000;
				}
			}
		}
		if(ver) cout << "NO CONFLICT\n";
		else cout << "CONFLICT\n";
		
		fore(j,0,1000001){
			bs.reset(j);
		}
	}
	return 0;
}
