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
typedef vector<vbool> vvbool;

vvbool dist;
ll n;

void fw(){
	fore(k,0,n){
		fore(i,0,n){
			fore(j,0,n){
				dist[i][j] = dist[i][j] | (dist[i][k] & dist[k][j]);
			}
		}
	}
}

int main(){FIN
	ll m;
	char q[6];
	vbool used;
	vvll ans;
	vll ansP;
	ll test = 0;

	while(cin >> m && m){
		if(test) cout << "\n";
		test++;	
		n=26;
		
		dist.assign(n,vbool(n,0));
		

		fore(i,0,m){
			fore(j,0,6){
				cin >> q[j];
				dist[q[j]-'A'][q[j]-'A']=1;
			}
			
			fore(j,0,5) dist[q[5]-'A'][q[j]-'A']=1;
		}

		fw();
		used.assign(n,0);
		fore(i,0,n){
			if(used[i])continue;
			fore(j,0,n){
				if(dist[i][j] && dist[j][i]){
					ansP.pb(j);
					used[j]=1;
				}
			}
			if(SZ(ansP)){
				sort(ALL(ansP));
				ans.pb(ansP);
				ansP.clear();
			}
		}

		fore(i,0,SZ(ans)){
			fore(j,0,SZ(ans[i])){
				if(j) cout << " ";
				cout << char('A'+ans[i][j]);
			}
			cout << "\n";
		}

		ans.clear();
	}
	return 0;
}
