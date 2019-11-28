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
	ll n,m;
	vvll grid;
	vll ss;

	cin >> n >> m;

	grid.assign(n,vll(m,0));
	ss.assign(n+m,0);

	fore(i,0,n){
		fore(j,0,m){
			cin >> grid[i][j];
			ss[i]+=grid[i][j];
			ss[n+j]+=grid[i][j];
		}
	}

	ll ans = 0;
	ll mV, mP;
	//ll c1,c2,p1,p2;
	
	fore(i,0,4){
		
		mV=-1e9;
		fore(j,0,(n+m)){
			if(ss[j]>mV){
				mV=ss[j];
				mP=j;
			}
		}
		if(mV == 0) break;
		/*c1 = c2 = 0;
		fore(j,0,(n+m)){
			if(ss[j]==mV){
				if(j>=n){
					c1++;
					p1 = j;
				}
				else{
					c2++;
					p2 = j;
				}
			}
		}
		if(c1 > c2) mP = p1;
		else mP = p2;
		*/
		ans += mV;
		
		if(mP >= n){
			fore(j,0,n){
				ss[j]-=grid[j][mP-n];
				grid[j][mP-n]=0;
				ss[j] = max(0ll,ss[j]);
			}
		}
		else{
			fore(j,0,m){
				ss[n+j]-=grid[mP][j];
				grid[mP][j]=0;
				ss[n+j] = max(0ll,ss[n+j]);
			}
		}
		ss[mP]=0;
	}
	cout << ans << "\n";
	return 0;
}
