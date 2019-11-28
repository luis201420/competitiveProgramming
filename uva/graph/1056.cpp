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
typedef map<string,ll> msl;

ll n;
vvll dist;

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
	
	ll m,cont,test=1,ans;
	msl ids;
	string p1,p2;
	bool disconnected;

	while(cin >> n >> m){
		if((n+m)==0) break;

		dist.assign(n,vll(n,1e9));

		cont = 1;
		while(m--){
			cin >> p1 >> p2;
			if(ids[p1]==0)ids[p1]=cont++;
			if(ids[p2]==0)ids[p2]=cont++;
			dist[ids[p1]-1][ids[p2]-1]=1;
			dist[ids[p2]-1][ids[p1]-1]=1;
			dist[ids[p1]-1][ids[p1]-1]=0;
			dist[ids[p2]-1][ids[p2]-1]=0;
		}
		
		fw();
		
		disconnected = 0;
		ans=0;
		fore(i,0,n){
			fore(j,0,n){
				if(dist[i][j]>=1e9){
					disconnected=1;
					break;
				}
				ans=max(ans,dist[i][j]);
			}
		}
		cout << "Network "<<test++<<": ";
		if(disconnected)cout << "DISCONNECTED\n";
		else cout << ans << "\n";
		ids.clear();
		cout  << "\n";
	}
	return 0;
}
