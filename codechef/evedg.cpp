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

vvll adj;
vll degree,color;

int main(){FIN
	
	ll t,n,m,a,b,p1,p2,mm;
	
	cin >> t;
	
	while(t--){
		cin >> n >> m;
		
		adj.assign(n,vll());
		degree.assign(n,0);
		color.assign(n,1);

		fore(jj,0,m){
			cin >> a >> b;
			a--;b--;
			adj[a].pb(b);
			adj[b].pb(a);
			degree[a]++;
			degree[b]++;
		}
		mm = 1;
		if(m&1){	
			p1 = -1;
			fore(i,0,n){
				if(degree[i]&1){
					p1=i;
					break;
				}
				else if(degree[i])p2=i;
			}
			if(p1!=-1){
				mm = 2;
				color[p1]=2;
			}
			else{
				mm = 3;
				color[p2]=2;
				color[adj[p2][0]]=3;
			}	
		}
		cout << mm << "\n";
		fore(i,0,n){
			if(i) cout << " ";
			cout << color[i];
		}
		cout << "\n";
	}
	return 0;
}
