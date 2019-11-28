#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) s.size()
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vstr;

const int dx[8] = {1,1,0,-1,-1,-1,0,1};
const int dy[8] = {0,1,1,1,0,-1,-1,-1};

int dfs(int x, int y, vstr& g, int N){
	
	if(x < 0 || x>=N || y < 0 || y>= SZ(g[0])) return 0;
	
	if(g[x][y]!='W')return 0;
	
	int ans = 1;
	g[x][y] = 'L';
	
	fore(i,0,8){
		ans += dfs(x+dx[i],y+dy[i],g,N);
	}
	//g[x][y] = 'W';
	return ans;
}

int main(){FIN

	ll q,n,m;
	int x,y;
	string s,query;
	vstr grid,gridC;

	cin >> q;
	
	getline(cin,s);
	getline(cin,s);
	
	fore(t,0,q){
		if(t!=0)cout << "\n";
		while(1){
			getline(cin,s);
			if(SZ(s)==0)break;
			grid.pb(s);
		}
		fore(i,0,SZ(grid)){
			if(grid[i][0]!='L' && grid[i][0]!='W'){n=i;break;}
		}
		fore(i,n,SZ(grid)){
			
			query = grid[i];

			fore(j,0,SZ(query)){
				if(query[j]==' '){m=j;break;}
			}
			x = atoi(query.substr(0,m).c_str());
			y = atoi(query.substr(m+1).c_str());
			//DBG(x); DBG(y);
			gridC=grid;
			cout << dfs(x-1,y-1,gridC,n) << "\n";
		}
		grid.clear();
	}
	return 0;
}
