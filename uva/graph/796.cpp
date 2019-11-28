#include <bits/stdc++.h>

using namespace std;

int n;
set<pair<int,int>> res;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin,fup;
int timer;

void dfs(int v,int p=-1){
	visited[v]=1;
	tin[v]=fup[v]=timer++;
	for(int to: adj[v]){
		if(to==p) continue;
		if(visited[to]){
			fup[v]=min(fup[v],tin[to]);
		}
		else{
			dfs(to,v);
			fup[v]=min(fup[v],fup[to]);
			if(fup[to] > tin[v])
				res.insert({min(v,to),max(v,to)});
		}
	}
}

int main(){
	int a,m,b,cont=0;
	string c;
	while(cin >> n){
		adj.assign(n,vector<int>());
		for(int i=0;i<n;i++){
			cin >> a >> c;
			m=atoi((c.substr(1,c.size()-2)).c_str());
			while(m--){
				cin >> b;
				adj[a].push_back(b);
			}
		}
		timer=0;
		visited.assign(n,0);
		tin.assign(n,-1);
		fup.assign(n,-1);
		for(int i=0;i<n;i++){
			if(!visited[i])
				dfs(i);
		}
		cout << res.size() << " critical links" << endl;
		for(auto it:res){
			cout << it.first << " - " << it.second << endl;
		}
		res.clear();
		cont++;
		cout << endl;
	}
	return 0;
}
