#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> match;
vector<bool> visited;

int aug(int ini){
	if(visited[ini]) return 0;
	visited[ini]=1;
	for(int i=0;i<graph[ini].size();i++){
		int r = graph[ini][i];
		if(match[r]==-1 || aug(match[r])){
			match[r]=ini;
			return 1;
		}
	}
	return 0;
}

int main(){
	int t,n,m,res;
	bool v;
	cin >> t;
	for(int c=1;c<=t;c++){
		cin >> n >> m;
		graph.assign(n,vector<int>());
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> v;
				if(v)graph[i].push_back(j);
			}
		}
		match.assign(m,-1);
		res=0;
		for(int i=0;i<n;i++){
			visited.assign(n,0);
			res+=aug(i);
		}
		cout << "Case "<<c<<": a maximum of "<<res <<" nuts and bolts can be fitted together\n";
	}
	return 0;
}
