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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<string> vstr;

vvvd dist;
vvvll p;
ll n;

void fw(){
	double tmp;
	fore(u,1,n){
		fore(k,0,n){
			fore(i,0,n){
				fore(j,0,n){
					tmp = dist[i][k][u-1]*dist[k][j][0];
					if(tmp>dist[i][j][u]){
						dist[i][j][u]=tmp;
						p[i][j][u]=k;
					}
				}
			}
		}
	}
}

int main(){FIN

	ll minS,id;
	vll ans;
	bool ver;

	while(cin >> n){
		
		dist.assign(20,vvd(20,vd(20,0)));
		p.assign(20,vvll(20,vll(20,0)));

		fore(i,0,n){
			fore(j,0,n){
				p[i][j][0]=i;
				if(i==j) dist[i][j][0]=1.0;
				else cin >>dist[i][j][0];
			}
		}
		
		fw();

		ver=0;
		fore(u,1,n){
			fore(i,0,n){
				if(dist[i][i][u]>1.01){
					ans.resize(u+1);
					ans[u]=p[i][i][u];
					for(int j=u-1;j>=0;j--){
						ans[j]=p[i][ans[j+1]][j];
					}
					fore(j,0,u+1){
						cout << ans[j]+1 << " ";
					}
					cout << ans[0]+1 << "\n";
					ver = 1;
					break;
				}
			}
			if(ver)break;
		}
		if(!ver) cout << "no arbitrage sequence exists\n";	
	}
	return 0;
}
