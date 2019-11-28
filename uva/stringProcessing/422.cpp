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
typedef vector<string> vstr;

const vll dx = {1,0,1,-1,-1,1,0};
const vll dy = {0,1,1, 1,-1,-1,-1};

int main(){FIN
	
	ll n;
	string q;
	vstr grid,qs;
	vector<bool> ver;
	vector<vll> ans;

	cin >> n;
	
	grid.resize(n);
	fore(i,0,n) cin >> grid[i];

	while(cin >> q){
		if(q=="0")break;
		qs.pb(q);
	}

	ll x,y,r;
	
	ver.assign(SZ(qs),1);
	ans.assign(SZ(qs),vll());


	fore(i,0,n){
		fore(j,0,n){
			fore(k,0,SZ(qs)){
				if(grid[i][j]==qs[k][0] && ver[k]){
					fore(l,0,SZ(dx)){
						x=i;y=j;r=0;
						while(0<=x && x<n && 0<=y && y<n && r<SZ(qs[k]) && grid[x][y]==qs[k][r]){
							x+=dx[l];
							y+=dy[l];
							r++;
						}
						if(r==SZ(qs[k])){
							ans[k]={i+1,j+1,x-dx[l]+1,y-dy[l]+1};
							ver[k]=0;
							break;
						}
					}
				}
			}
		}
	}

	fore(i,0,SZ(ans)){
		if(SZ(ans[i])==0) cout << "Not found\n";
		else cout << ans[i][0] << "," << ans[i][1] << " " << ans[i][2] << "," << ans[i][3] << "\n";
	}

	return 0;
}
