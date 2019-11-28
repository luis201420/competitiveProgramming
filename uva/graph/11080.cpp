#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

vector<int> color,cont;

int n;

bool bfs(int s){
	queue<int> q;
	color[s]=/*(cont[0]<cont[1]) ? 1 :*/ 0;
	cont[color[s]]++;
	bool isBipartite=1;
	q.push(s);
	int u,v;
	while(!q.empty() && isBipartite){
		u=q.front();q.pop();
		for(int i=0;i<adj[u].size();i++){
			v=adj[u][i];
			if(color[v] == -1){
				color[v]=1-color[u];
				cont[color[v]]++;
				q.push(v);
			}
			else if(color[v] == color[u]){
				isBipartite=0;break;
			}
		}
	}
	return isBipartite;
}

int main(){
	int t,a,b,e,res;
	cin >> t;
	while(t--){
		cin >> n >> e;
		if(e == 0){
			cout << n << endl;
			continue;
		}
		adj.assign(n,vector<int>());
		for(int i=0;i<e;i++){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}	
		color.assign(n,-1);
		bool v=1;
		res = 0;
		for(int i=0;i<n;i++){
			if(adj[i].size()==0){
				res++;
				continue;
			}
			cont.assign(2,0);
			if(color[i]==-1){
				v=bfs(i);
				res+=min(cont[0],cont[1]);
			}
			if(!v)break;
		}
		if(v){
			cout << res << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}
