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
typedef vector<bool> vbool;
typedef vector<vbool> vvbool;

vvbool used;
vbool ver;
string grid[4];
vstr qs;
ll ans;

const vll dx = {1,1,1,0,-1,-1,-1,0};
const vll dy = {1,0,-1,-1,-1,0,1,1};

void bt(ll i, ll j, ll idS, ll cur){
	
	used[i][j]=1;
	
	if(SZ(qs[idS])==cur){
		ver[idS]=1;
		ll ss = SZ(qs[idS]);
		if(ss > 2 && ss <=4) ans++;
		else if(ss == 5) ans+=2;
		else if(ss == 6) ans+=3;
		else if(ss == 7) ans+=5;
		else if(ss >= 8) ans+=11;
		return;
	}
	
	ll ax,ay;
	
	fore(k,0,8){
		ax = i + dx[k];
		ay = j + dy[k];
		if(0<=ax && ax<4 && 0<=ay && ay<4 && grid[ax][ay]==qs[idS][cur] && !used[ax][ay]){
			bt(ax,ay,idS,cur+1);
			if(ver[idS])break;
		}
	}
	used[i][j]=0;
}

int main(){FIN
	ll t,q;
	
	cin >> t;
	fore(tt,0,t){
		
		cout << "Score for Boggle game #" << tt+1 << ": ";
		fore(i,0,4) cin >> grid[i];
		
		cin >> q;
		
		qs.resize(q);
		fore(i,0,q) cin >> qs[i];
		
		ans = 0;
		ver.assign(q,0);

		fore(i,0,4){
			fore(j,0,4){
				fore(k,0,q){
					if(ver[k])continue;
					if(grid[i][j]==qs[k][0]){
						used.assign(4,vbool(4,0));
						bt(i,j,k,1);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
