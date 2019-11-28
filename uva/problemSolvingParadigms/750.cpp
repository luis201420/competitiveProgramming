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

ll n,px,py;
vbool diag1,diag2;
vll col;
vvll ans,all;

void search(ll y){
	if(y==n){
		all.pb(col);
		return ;
	}
	fore(x,0,n){
		if(col[x]!=-1 || diag1[x+y] || diag2[x-y+n-1])continue;
		col[x] = y;
		diag1[x+y] = diag2[x-y+n-1] = 1;
		search(y+1);
		col[x] = -1;
		diag1[x+y] = diag2[x-y+n-1] = 0;
	}
}

void searchAll(){
	fore(i,0,SZ(all)){
		if(all[i][px]==py)ans.pb(all[i]);
	}
}

int main(){FIN
	ll t;
	
	cin >> t;

	n=8;
	col.assign(n,-1);
	diag1.assign(2*n-1,0);
	diag2.assign(2*n-1,0);	
		
	search(0);

	fore(tt,0,t){
		if(tt)cout << "\n";	
		cin >> py >> px;
		px--;py--;	

		searchAll();

		sort(ALL(ans));
		
		cout << "SOLN       COLUMN\n";
		cout << " #      1 2 3 4 5 6 7 8\n\n";

		fore(i,0,SZ(ans)){
			if((i+1) < 10) cout << " ";
			cout << i+1 << "      ";
			fore(j,0,SZ(ans[i])){
				if(j)cout << " ";
				cout << ans[i][j]+1;
			}
			cout << "\n";
		}
		ans.clear();
	}
	return 0;
}
