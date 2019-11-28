#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> match;

bool aug(int ini){
	if(visited[ini]) return 0;
	visited[ini] = 1;
	for(int i=0;i<adj[ini].size();i++){
		int r = adj[ini][i];
		if(match[r]==-1 || aug(match[r])){
			match[r]=ini;
			return 1;
		}
	}
	return 0;
}

void create(int u,string s,int w){
	int pos;
	if(s=="XXL") pos = 0;
	if(s=="XL") pos = w;
	if(s=="L") pos = 2*w;
	if(s=="M") pos = 3*w;
	if(s=="S") pos = 4*w;
	if(s=="XS") pos = 5*w;
	for(int k=0;k<w;k++){
		adj[pos+k].push_back(u);
	}
}

int main(){
	int t,n,m,res;
	string s1,s2;
	cin >> t;
	while(t--){
		cin >> n >> m;
		adj.assign(n,vector<int>());
		for(int i=0;i<m;i++){
			cin >> s1 >> s2;
			create(i,s1,n/6);
			create(i,s2,n/6);
		}
		match.assign(m,-1);
		res = 0;
		for(int i=0;i<n;i++){
			visited.assign(n,0);
			res+=aug(i);
		}
		if(res==m) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}
