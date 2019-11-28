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
typedef vector<bool> vbool;
typedef vector<vbool> vvbool;

vvbool g;
vll dist;
ll n,m;

vll dx = {1,0,-1,0};
vll dy = {0,-1,0,1};

bool isFree(ll &x, ll &y){
	if(x<0 || x>=(n-1) || y<0 || y>=(m-1))return 0; 
	if((x+1)<n && (y+1)<m){
	 if(g[x][y] && g[x+1][y] && g[x][y+1] && g[x+1][y+1]) return 1;
	 else return 0;
	}
	else return 0;
}

void bfs(ll &x, ll &y, string &orient){
	
	ll dir;
	if(orient=="south") dir = 0;
	if(orient=="north") dir = 2;
	if(orient=="east")  dir = 3;
	if(orient=="west")  dir = 1;
	
	dist[(x*m)+y]=0;
	
	ll ux,uy,uid,vx,vy,vid,aux;
	queue<pair<pll,ll>> q;
	pair<pll,ll> u;

	q.push({{x,y},dir});

	while(!q.empty()){
		u = q.front(); q.pop();
		ux = u.fst.fst;
		uy = u.fst.snd;
		uid = (ux*m)+uy;

		fore(i,0,4){
			fore(j,1,4){
				vx = ux + (j*dx[i]);
				vy = uy + (j*dy[i]);
				if(isFree(vx,vy)){
					
					vid = (vx*m)+vy;

					if(i == u.snd) aux = dist[uid]+1;
					else if(i == (u.snd+2)%4) aux=dist[uid]+3;
					else aux=dist[uid]+2;

					if(dist[vid] == 1e9){

						dist[vid] = aux;
						
						/*if(i == u.snd) dist[vid]++;
						else if(i == (u.snd+2)%4) dist[vid]+=3;
						else dist[vid]+=2;*/

						q.push({{vx,vy},i});
					}
				}
				else break;
			}
		}
	}
}

int main(){FIN
	ll v;
	ll x,y,ox,oy;
	string orient;

	while(cin >> n >> m){
		
		if((n+m) == 0)break;

		g.assign(n,vbool(m,1));

		fore(i,0,n){
			fore(j,0,m){
				cin >> v;
				if(v)g[i][j]=0;
			}
		}

		cin >> x >> y >> ox >> oy >> orient;
		
		dist.assign(n*m,1e9);

		x--;y--;ox--;oy--;
		if(isFree(x,y) && isFree(ox,oy))
			bfs(x,y,orient);
		if(dist[(ox*m)+oy]<1e9)cout << dist[(ox*m)+oy] << "\n";
		else cout << "-1\n";
		/*fore(i,0,n){
			fore(j,0,m){
				if(dist[(i*m)+j] < 1e9){
					cout << dist[(i*m)+j];
					if(dist[(i*m)+j]<10) cout << "  ";
					else cout << " ";
				}
				else cout << "-1 ";
			}
			cout << endl;
		}*/
	}
	return 0;
}
