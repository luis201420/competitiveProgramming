#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

vector<int> match;
vector<bool> visited;

int aug(int ini){
	if(visited[ini])return 0;
	visited[ini]=1;
	for(int i=0;i<adj[ini].size();i++){
		int r=adj[ini][i];
		if(match[r]==-1 || aug(match[r])){
			match[r]=ini;
			return 1;
		}
	}
	return 0;
}

int main(){
	iostream::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string l,r;
	getline(cin,l);
	getline(cin,l);
	getline(cin,r);
	//cin >> l >> r;
	adj.assign(n,vector<int>());
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(l[i]=='?' || r[j]=='?'){
				adj[i].push_back(j);
			}
			else if(l[i]==r[j]){
				adj[i].push_back(j);
			}
		}
	}

	match.assign(n,-1);
	int res=0;
	for(int i=0;i<n;i++){
		visited.assign(n,0);
		res+=aug(i);
	}

	cout << res << endl;
	for(int i=0;i<n;i++){
		if(match[i]!=-1){
			cout << match[i]+1 << " " << i+1 << endl;
		}
	 }
	return 0;
}
