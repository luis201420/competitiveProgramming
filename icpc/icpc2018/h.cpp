#include <bits/stdc++.h>

using namespace std;

#define INF (1ll << 60)

struct Highways{
	long long v,l,c;
};

vector<long long> parent;
vector<vector<Highways>> adj;
int n;

void dijkstra(){
	vector<long long> dist(n,INF);
	vector<bool> used(n,0);
	parent.assign(n,INF);
	dist[0]=0;
	parent[0]=0;
	priority_queue<vector<long long>> q;
	q.push({0,0,0});
	while(!q.empty()){
		long long a = q.top()[2];q.pop();
		if(used[a])continue;
		used[a]=1;
		for(auto u : adj[a]){
			long long b = u.v , L = u.l , C = u.c;
			if(dist[a]+L < dist[b]){
				dist[b]=dist[a]+L;
				parent[b]=C;
				q.push({-dist[b],-parent[b],b});
			}
			else if(dist[a]+L == dist[b] && C < parent[b]){
				parent[b]=C;
				q.push({-dist[b],-parent[b],b});
			}
		}
	}
}

int main(){
	int m;
	long long U,V,L,C;
	cin >> n >> m;
	adj.assign(n,vector<Highways>());
	while(m--){
		cin >> U >> V >> L >> C;
		adj[U-1].push_back({V-1,L,C});
		adj[V-1].push_back({U-1,L,C});
	}
	dijkstra();
	long long res = 0;
	for(int i=0;i<parent.size();i++)res+=parent[i];
	cout << res << endl;
	return 0;
}
