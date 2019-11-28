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
typedef pair<double,double> pll;
typedef pair<int,int> pii;
typedef vector<string> vstr;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<vbool> vvbool;


int main(){FIN
	ll n,ans,p;
	vpll seg;
	double l,r,pos,dx,maxV,cur,w;
	
	while(cin >> n >> l >> w){
		fore(i,0,n){
			cin >> pos >> r;
			if(r > (w/2.0)){
				dx = sqrt( double(SQR(r)) - double(SQR(w/2.0)));
				seg.pb({double(pos)-dx,double(pos)+dx});
			}
		}
		sort(ALL(seg));
		
		cur = 0;
		ans = 0;
		fore(i,0,SZ(seg)){
			p = i;
			maxV = -1e9;
			while(p<SZ(seg) && seg[p].fst <= cur){
				maxV = max(maxV,seg[p].snd);
				p++;
			}
			if(p==i) break;
			ans++;
			cur=maxV;
			p=i-1;
			if(cur >= l)break;
		}

		if(cur >= l) cout << ans;
		else cout << "-1";
		cout << "\n";

		seg.clear();
	}
	return 0;
}
