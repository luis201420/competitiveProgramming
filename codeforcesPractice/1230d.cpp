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

	ll ans,n;
	vpll st;
	vll c;
	vbool used;

	cin >> n;
	
	st.assign(n,pll());
	c.assign(n,0);
	used.assign(n,1);

	fore(i,0,n) cin >> st[i].fst;
       	fore(i,0,n) cin >> st[i].snd;
	
	fore(i,0,n){
		fore(j,0,n){
			if(i==j)continue;
			if(st[i].fst == st[j].fst)c[i]++;
		}
	}
	ans = 0;
	fore(i,0,n){
		if(c[i]){
			fore(j,0,n){
				if((st[i].fst & st[j].fst) == st[j].fst){
					if(used[j]){
						used[j]=0;
						ans+=st[j].snd;
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
