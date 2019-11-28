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

struct Element{
	ll v,x,y;
};

bool myComp(const Element &e1, const Element &e2){
	return e1.v > e2.v;
}

int main(){FIN
	ll t,n,m,ans,v;
	vector<Element> vs;
	vll col;

	cin >> t;
	while(t--){
		cin >> n >> m;
		col.assign(m,-1e9);
		fore(i,0,n){
			fore(j,0,m){
				cin >> v;
				vs.pb({v,i,j});
			}
		}
		sort(ALL(vs),myComp);
		ans = 0;
		v = 0;
		fore(i,0,n){
			fore(j,v,SZ(vs)){
				if(col[vs[j].y]==-1e9){
					ans +=  vs[j].v;
					col[vs[j].y] = (i-vs[j].x);
					v=j+1;
					break;	
				}
				else{
					if(((vs[j].x+n)-col[vs[j].y])%n == i){
						ans += vs[j].v;
						v=j+1;
						break;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
