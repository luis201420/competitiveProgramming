#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef pair<int,int> pii;
typedef vector<string> vstr;

int main(){FIN
	ll n,m,v;

	cin >> n >> m;
	
	bool ver=1;

	vvll A(n,vll(m,0)),B(n,vll(m,0));
	
	fore(i,0,n){
		fore(j,0,m){
			cin >> v;
			A[i][j]=v;
		}
	}

	vpll ans;
	
	fore(i,0,n-1){
		fore(j,0,m-1){
			if(A[i][j] && A[i][j+1] && A[i+1][j]&& A[i+1][j+1]){
				B[i][j] = B[i][j+1] = B[i+1][j] = B[i+1][j+1]=1;
				ans.pb({i+1,j+1});
			}
		}
	}
	fore(i,0,n){
		fore(j,0,m){
			if(A[i][j]!=B[i][j]){ver=0;break;}
		}
	}
	if(ver){
		cout << SZ(ans) << "\n";
		fore(i,0,SZ(ans)) cout << ans[i].fst << " " << ans[i].snd << "\n";
	}
	else cout << "-1\n";
	return 0;
}
