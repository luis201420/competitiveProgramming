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
	vector<int> A;
	int t,n,m,v,res;
	cin >> t;
	for(int c=1;c<=t;c++){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> v;
			A.push_back(v);
		}
		cin >> m;
		graph.assign(n,vector<int>());
		for(int i=0;i<m;i++){
			cin >> v;
			for(int j=0;j<A.size();j++){
				if(A[j]==0){
					if(v==0)graph[j].push_back(i);
					continue;
				}
				if(v%A[j]==0)graph[j].push_back(i);
			}
		}
		match.assign(m,-1);
		res = 0;

		for(int i=0;i<n;i++){
			visited.assign(n,0);
			res+=aug(i);
		}
		cout << "Case "<<c << ": "<<res << endl;
		A.clear();
	}
	return 0;
}
