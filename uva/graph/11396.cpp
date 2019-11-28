#include <bits/stdc++.h>

using namespace std;

int n,a,b;
vector<vector<int>> adj;
vector<int> color;

bool bfs(int s){
	queue<int> q;
	bool isBipartite = 1;
	color[s]=0;
	q.push(s);
	int u,v;
	while(!q.empty() && isBipartite){
		u=q.front();q.pop();
		for(int i=0;i<adj[u].size();i++){
			v=adj[u][i];
			if(color[v]==-1){
				color[v]=1-color[u];
				q.push(v);
			}
			else if(color[v] == color[u]){
				isBipartite=0; break;
			}
		}
	}
	return isBipartite;
}

int main(){
	bool res;
	while(cin >> n){
		if(n == 0) break;
		adj.assign(n,vector<int>());
		while(cin >> a >> b){
			if(a==0 && b ==0) break;
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1);
		}
		color.assign(n,-1);
		res=1;
		for(int i=0;i<n;i++){
			if(color[i]==-1)res&=bfs(i);
		}	
		if(res)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}
