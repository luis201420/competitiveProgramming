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
	ll p,n,s,ss,ans,area;
	ll r1,c1,r2,c2;
	vvll board;

	cin >> p;
	while(p--){
		cin >> n >> s;
		
		board.assign(n,vll(n,1));
		
		while(s--){
			cin >> r1 >> c1 >> r2 >> c2;
			r1--;r2--;c1--;c2--;

			fore(i,r1,r2+1){
				fore(j,c1,c2+1){
					board[i][j]=0;
				}
			}	
		}
		fore(i,0,n){
			fore(j,0,n){
				if(i > 0) board[i][j] += board[i-1][j];
				if(j > 0) board[i][j] += board[i][j-1];
				if(i > 0 && j > 0) board[i][j] -= board[i-1][j-1];
			}
		}
		ans = 0;
		fore(i,0,n){
			fore(j,0,n){
				fore(k,i,n){
					fore(l,j,n){
						ss = board[k][l];
						if(i > 0) ss -= board[i-1][l];
						if(j > 0) ss -= board[k][j-1];
						if(i > 0 && j > 0) ss += board[i-1][j-1];
						area = (k-i+1)*(l-j+1);
						if(ss == area)ans = max(ans,ss);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
