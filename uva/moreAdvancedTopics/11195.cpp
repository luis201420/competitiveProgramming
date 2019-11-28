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

ll ans,n;
vbool diag1,diag2,col;
vstr board;

void search(ll y){
	if(y==n){
		ans++;
		return ;
	}
	fore(x,0,n){
		if(col[x] || diag1[x+y] || diag2[x-y+n-1] || board[y][x]=='*')continue;
		col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
		search(y+1);
		col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
	}
}

int main(){FIN
	ll test=1;
	while(cin >> n && n){
		board.resize(n);
		col.assign(n,0);
		diag1.assign(2*n-1,0);
		diag2.assign(2+n-1,0);
		fore(i,0,n)cin >> board[i];
		ans=0;
		//DBG(test);
		search(0);
		cout <<"Case "<< test++ << ": "<< ans << "\n";
	}
	return 0;
}
