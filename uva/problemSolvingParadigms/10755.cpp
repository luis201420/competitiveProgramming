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
typedef vector<vvll> vvvll;

int main(){FIN
	ll t,a,b,c,s,ans,ss;
	vvvll A;
	
	cin >> t;
	
	fore(tt,0,t){
		if(tt) cout << "\n";
		
		cin >> a >> b >> c;
		
		A.assign(a,vvll(b,vll(c,0)));

		fore(i,0,a){
			fore(j,0,b){
				fore(k,0,c){
					cin >> A[i][j][k];
					if(j > 0) A[i][j][k] += A[i][j-1][k];
					if(k > 0) A[i][j][k] += A[i][j][k-1];
					if(j > 0 && k > 0) A[i][j][k] -= A[i][j-1][k-1];
				}
			}
		}
		
		ans = -1e18;

		fore(j,0,b){
			fore(k,0,c){
				fore(jj,j,b){
					fore(kk,k,c){
						ss = 0;
						fore(i,0,a){
							s = A[i][jj][kk];
							if(j > 0) s -= A[i][j-1][kk];
							if(k > 0) s -= A[i][jj][k-1];
							if(j > 0 && k > 0) s += A[i][j-1][k-1];
							ss += s;
							ans = max(ans,ss);
							if(ss < 0) ss = 0;
						}
					}
				}
			}
		}

		cout << ans << "\n";

	}
	return 0;
}
