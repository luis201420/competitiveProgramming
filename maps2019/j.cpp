#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> all;
vector<int> match;
vector<bool> visited;

int n,m;

int aug(int ini){
	if(visited[ini])return 0;
	visited[ini]=1;
	for(int i=0;i<all[ini].size();i++){
		int r = all[ini][i];
		if(match[r]==-1 || aug(match[r])){
			match[r]=ini;
			return 1;
		}
	}
	return 0;
}

int  main(){
	int T,t;
	cin >> n >> m;
	all.assign(m,vector<int>());
	for(int i=0;i<n;i++){
		cin >> T;
		for(int j=0;j<T;j++){
			cin >> t;
			all[t-1].push_back(i);
		}
	}
	match.assign(n,-1);
	int res=0;
	for(int i=0;i<all.size();i++){
		visited.assign(m,0);
		res+=aug(i);
	}
	cout << res << endl;
	return 0;
}
