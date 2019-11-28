#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> match;

bool aug(int ini){
	if(visited[ini])return 0;
	visited[ini]=1;
	for(int i=0;i<adj[ini].size();i++){
		int r = adj[ini][i];
		if(match[r]==-1 || aug(match[r])){
			match[r]=ini;
			return 1;
		}
	}
	return 0;
}

int main(){
	int n,m,p,c,b,res;
	cin >> n >> m >> p;
	adj.assign(n,vector<int>());
	for(int i=0;i<p;i++){
		cin >> c >> b;
		adj[c-1].push_back(b-1);
	}
	res=0;
	match.assign(m,-1);
	for(int i=0;i<n;i++){
		visited.assign(n,0);
		res+=aug(i);
	}
	cout << res << endl;
	return 0;
}
