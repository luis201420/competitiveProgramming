#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<long long,long long>>> adj;
vector<bool> visited;
vector<long long> dist;
vector<long long> previous;
long long n ;

void dijkstra(){
	priority_queue<pair<long long,long long>> q;
	dist.assign(n,(1ll<<60));
	visited.assign(n,0);
	previous.assign(n,-1);
	dist[0]=0;
	q.push({0,0});
	while(!q.empty()){
		long long a=q.top().second; q.pop();
		if(visited[a])continue;
		visited[a]=1;
		for(auto u:adj[a]){
			long long b = u.first; long long w=u.second;
			if(dist[a]+w < dist[b]){
				dist[b]=dist[a]+w;
				previous[b]=a;
				q.push({-dist[b],b});
			}
		}
	}
}

int main(){
	long long m,a,b;
	long long w;
	vector<int> res;
	cin >> n >> m;
	adj.assign(n,vector<pair<long long,long long>>());
	while(m--){
		cin >> a >> b >> w;
		adj[a-1].push_back({b-1,w});
		adj[b-1].push_back({a-1,w});
	}
	dijkstra();
	int j=n-1;
	res.push_back(n);
	while(previous[j]!=-1){
		res.push_back(previous[j]+1);
		j=previous[j];
	}
	if(res.size()==1) cout << -1 << endl;
	else{
		for(int i=res.size()-1;i>=0;i--){
			cout << res[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
