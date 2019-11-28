#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<long long> dist;
vector<bool> visited;
int n,m;

void dijkstra(int r){
	priority_queue<pair<int,int>> q;
	visited.assign(n,0);
	dist.assign(n,1e18);
	dist[r]=0;
	q.push({0,r});
	int u;
	while(!q.empty()){
		u=q.top().second;
		q.pop();
		if(visited[u])continue;
		visited[u]=1;
		for(auto it:adj[u]){
			if(dist[it.first]>dist[u]+it.second){
				dist[it.first]=dist[u]+it.second;
				q.push({-dist[it.first],it.first});
			}
		}
	}
}

int main(){
	int s,q;
	int a,b,c;
	int cont = 0;
	while(cin >> n >> m >> q >> s){
		
		if(n+m+q+s == 0) break;
		if(cont!=0)cout << endl;
		adj.assign(n,vector<pair<int,int>>());
		for(int i=0;i<m;i++){
			cin >> a >> b >> c;
			adj[a].push_back({b,c});
		}
		dijkstra(s);
		while(q--){
			cin >> a;
			if(!visited[a])cout << "Impossible" << endl;
			else cout << dist[a] << endl;
		}
		cont++;
	}	
	return 0;
}
