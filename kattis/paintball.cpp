#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> match;
vector<bool> visited;

int aug(int ini){
	if(visited[ini])return 0;
	visited[ini]=1;
	for(int i=0;i<graph[ini].size();i++){
		int r=graph[ini][i];
		if(match[r]==-1 || aug(match[r])){
			match[r]=ini;
			return 1;
		}
	}
	return 0;
}

int main(){
	int n,m,a,b,res;
	cin >> n >> m;
	vector<int> ans(n);
	graph.assign(n,vector<int>());
	for(int i=0;i<m;i++){
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	match.assign(n,-1);
	res=0;
	for(int i=0;i<n;i++){
		visited.assign(n,0);
		res+=aug(i);
	}
	if(res==n){
		for(int i=0;i<match.size();i++){
			ans[match[i]]=i;
		}
		for(int i=0;i<ans.size();i++){
			cout << ans[i]+1 << endl;
		}
	}
	else{
		cout << "Impossible" << endl;
	}
	return 0;
}
