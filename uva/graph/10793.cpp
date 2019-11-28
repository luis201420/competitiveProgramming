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
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<string> vstr;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;

vvll dist;
ll n;

void fw(){
	fore(k,0,n){
		fore(i,0,n){
			fore(j,0,n){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}

int main(){FIN

	ll t,m,ans,aux,a,b,c;
	bool ver;

	cin >> t;
	fore(tt,1,t+1){
		cin >> n >> m;
		dist.assign(n,vll(n,1e9));
		fore(i,0,m){
			cin >> a >> b >> c;
			dist[a-1][b-1]=min(dist[a-1][b-1],c);
			dist[b-1][a-1]=min(dist[b-1][a-1],c);
			dist[a-1][a-1]=0;
			dist[b-1][b-1]=0;
		}

		fw();

		ans = 1e9;
		fore(i,5,n){
			aux = dist[i][0];
			ver = 1;
			fore(j,1,5){
				if(aux!=dist[i][j]){ver=0;break;}
			}
			if(ver){
				aux=-1e9;
				fore(j,0,n){
					aux=max(aux,dist[i][j]);
				}
				ans=min(ans,aux);
			}
		}
		cout << "Map " << tt << ": ";
		if(ans<1e9) cout << ans << "\n";
		else cout << -1 << "\n";
	}
	return 0;
}
