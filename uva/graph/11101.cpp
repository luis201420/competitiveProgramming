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
typedef vector<vll> vvll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vstr;

vvll grid,dist;

vll dx = {1,-1,0,0};
vll dy = {0,0,1,-1};

ll ans;

void bfs(queue<pll> &q){
	pll u;
	ll ux,uy,x,y;

	while(!q.empty()){
		u = q.front(); q.pop();
		
		ux = u.fst;
		uy = u.snd;

		if(grid[ux][uy]==2){
			ans = dist[ux][uy];
			break;
		}

		fore(i,0,4){
			x = ux + dx[i];
			y = uy + dy[i];
			if(0<=x && x<2001 && 0<=y && y<2001 && dist[x][y]==-1){
				dist[x][y]=dist[ux][uy]+1;
				q.push({x,y});
			}
		}
	}
}

int main(){FIN
	ll p,x,y;

	while(cin >> p){
		if(p==0)break;
		grid.assign(2001,vll(2001,0));
		dist.assign(2001,vll(2001,-1));
		queue<pll> q;
		fore(i,0,p){
			cin >> x >> y;
			grid[x][y] = 1;
			dist[x][y] = 0;
			q.push({x,y});
		}
		cin >> p;
		fore(i,0,p){
			cin >> x >> y;
			grid[x][y] = 2;
		}

		ans = -1;
		bfs(q);
		cout << ans << "\n";
	}
	return 0;
}
