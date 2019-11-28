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
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vstr;

vll dx = {1,1,1,0,-1,-1,-1,0};
vll dy = {1,0,-1,-1,-1,0,1,1};

int main(){FIN

	ll t,n,m,q,x,y,cont;
	string s;
	vstr grid,qs;
	vector<bool> cal;
	vpii ans;

	cin >> t;
	
	fore(z,0,t){
		if(z) cout << "\n";
		cin >> n >> m;
	
		fore(i,0,n){
			cin >> s;
			grid.pb(s);
		}
	
		cin >> q;
		fore(i,0,q){
			cin >> s;
			qs.pb(s);
		}
		
		cal.assign(q,0);
		ans.assign(q,pii());
		
		fore(i,0,n){
			fore(j,0,m){
				fore(k,0,q){
					if(cal[k])continue;
					if(tolower(grid[i][j])==tolower(qs[k][0])){
						fore(d,0,8){
							x=i;y=j;cont=0;
							while(x>=0 && y>=0 && x<n && y<m && cont<SZ(qs[k]) && tolower(grid[x][y])==tolower(qs[k][cont])){
								x+=dx[d];y+=dy[d];cont++;
							}
							if(cont == SZ(qs[k])){
								cal[k]=1;
								ans[k]={i+1,j+1};
								break;
							}
						}
					}
				}	
			}
		}

		fore(i,0,q){
			cout << ans[i].fst << " " << ans[i].snd << "\n";
		}

		grid.clear();
		qs.clear();
	}
	return 0;
}
