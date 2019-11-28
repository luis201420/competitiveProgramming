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

vector<vll> adj;
vector<bool> used;

/*void dfs(int u,int ant,int k,int c){
	if(c==k){
		used[u]=0;
		c=0;
		cout << char('A'+u) << " ";
	}
	ll v;
	bool ver = 1;

	sort(ALL(adj[u]));
	fore(i,0,SZ(adj[u])){
		v=adj[u][i];
		if(v==ant) continue;
		if(used[v]){
			ver = 0;
			dfs(v,u,k,c+1);
			break;
		}
	}
	if(ver) cout << "/" << char('A'+u) << "\n";
}*/

void dfs(int u, int ant, int k, int c){
	stack<vector<ll>> q;
	q.push({u,ant,c});
	vll x;
	ll v;
	bool ver,al;
	while(!q.empty()){
		x=q.top(); q.pop();
		al=0;
		if(x[2]==k){
			used[x[0]]=0;
			x[2]=0;
			al=1;
		}
		ver=1;
		//sort(ALL(adj[x[0]]));
		fore(i,0,SZ(adj[x[0]])){
			v = adj[x[0]][i];
			if(v==x[1])continue;
			if(used[v]){
				ver = 0;
				q.push({v,x[0],x[2]+1});
				break;
			}
		}
		if(ver) cout << "/" << char('A'+x[0]) << "\n";
		else if(al) cout << char('A'+x[0]) << " ";
	}
}

int main(){FIN
	int u,v,k;
	string s;
	while(getline(cin,s)){
		if(s=="#")break;
		
		adj.assign(26,vll());
		used.assign(26,1);
		
		fore(i,0,SZ(s)){
			u=s[i]-'A';
			if(s[i+1]==':'){
				i+=2;
				while(i<SZ(s) && s[i]!=';' && s[i]!='.'){
					v = s[i]-'A';
					adj[u].pb(v);
					i++;
				}
			}
			else i++;
			if(s[i]=='.'){
				u = s[i+2]-'A';
				v = s[i+4]-'A';
				k = atoi(s.substr(i+6).c_str());
				break;
			}
		}
		//DBG(u);
		dfs(u,v,k,1);
	}
	return 0;
}
