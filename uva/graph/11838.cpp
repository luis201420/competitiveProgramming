#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> dfs_num, dfs_low;
vector<bool> visited;
stack<int> S;
int dfsNumberCounter,res;

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push(u);
	visited[u]=1;
	int v;
	for(int i=0;i<adj[u].size();i++){
		v = adj[u][i];
		if(dfs_num[v] == -1)
			tarjanSCC(v);
		if(visited[v])
			dfs_low[u]=min(dfs_low[u],dfs_low[v]);
	}

	if(dfs_num[u] == dfs_low[u]){
		res++;
		while(!S.empty()){
			v = S.top(); S.pop();
			visited[v]=0;
			if(u == v) break;
		}
	}
}

int main(){
	int n,m;
	int a,b,t;
	while(cin >> n >> m){
		if(n==0 && m==0)break;
		adj.assign(n,vector<int>());
		dfs_num.assign(n,-1);
		dfs_low.assign(n,0);
		visited.assign(n,0);
		while(m--){
			cin >> a >> b >> t;
			adj[a-1].push_back(b-1);
			if(t==2)adj[b-1].push_back(a-1);
		}
		res=0;
		dfsNumberCounter=0;
		for(int i=0;i<n;i++){
			if(dfs_num[i] == -1)
				tarjanSCC(i);
		}
		if(res==1)cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
