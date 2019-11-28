#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<int> dist;
vector<bool> visited;

void dijkstra(int x){
	dist[x]=0;
	priority_queue<pair<int,int>> q;
	q.push({0,x});
	while(!q.empty()){
		int cur=q.top().second; q.pop();
		if(visited[cur]) continue;
		visited[cur]=1;
		for(auto u:adj[cur]){
			int s=u.first,w=u.second;
			if(dist[cur]+w < dist[s]){
				dist[s]=dist[cur]+w;
				q.push({-(dist[s]),s});
			}
		}
	}
}

int main(){
	int nt,n,e,t,m,a,b,c,res;
	cin >> nt;
	for(int k=0;k<nt;k++){
		if(k!=0)cout << endl;
		cin >> n >> e >> t >> m;
		adj.assign(n,vector<pair<int,int>>());
		while(m--){
			cin >> a >> b >> c;
			adj[b-1].push_back({a-1,c});
		}
		visited.assign(n,0);
		dist.assign(n,1e9);
		dijkstra(e-1);
		res = 0;
		for(int i=0;i<dist.size();i++){
			if(dist[i]<=t)res++;
		}
		cout << res << endl;
	}
	return 0;
}
