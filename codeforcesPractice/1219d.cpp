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
	ll n,k,A,v,ans;
	vll x,c;

	cin >> n >> k;
	x.resize(n);
	c.resize(n);
	fore(i,0,n) cin >> x[i];
	cin >> A;
	fore(i,0,n) cin >> c[i];

	ll p = 0;
	ans = 0;
	priority_queue<ll> q;
	bool ver = 1;
	while(p < n){
		
		while(p < n && k >= x[p]){
			q.push(-c[p]);
			p++;
		}
		if(p>=n) break;
		q.push(-c[p]);
		while(!q.empty()){
			v=-(q.top());q.pop();
			k += A;
			ans += v;
			if(k >= x[p])break;
		}
		if(k < x[p]){ver=0;break;}
		p++;
	}

	if(ver) cout << ans << "\n";
	else cout << "-1\n";
	return 0;
}
