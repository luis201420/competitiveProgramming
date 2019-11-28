#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> stateNodes,maxConsecutive;
int rest;

void dfs(int r, int maxC , int cur){
	if(adj[r].size()==1 && visited[adj[r][0]]){
		maxC = max(maxC,cur);
		if(maxC<=m)rest++;
		return;
	}
	string aux;
	for(int i=0;i<adj[r].size();i++){
		if(!visited[adj[r][i]]){
			visited[adj[r][i]]=1;
			if(stateNodes[adj[r][i]]==0){
				dfs(adj[r][i],max(maxC,cur),0);
			}
			else
				dfs(adj[r][i],maxC,cur+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	stateNodes.resize(n);
	for(int i=0;i<n;i++){
		cin >> stateNodes[i];
	}
	adj.assign(n,vector<int>());
	int a,b;
	for(int i=1;i<n;i++){
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	visited.assign(n,0);
	visited[0]=1;
	rest = 0;
	dfs(0,0,stateNodes[0]);
	cout << rest << endl;
	return 0;
}
