#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> adj;
vector<vector<long long>> capacity;
map<pair<int,int>,long long>edgesAns;

int n;
const ll inf = (ll)1 << 60;

long long bfs(int s, int t, vector<int>& parent){
	fill(parent.begin(),parent.end(),-1);
	parent[s] = -2;

	queue<pair<int,long long>> q;
	q.push({s,inf});
	while(!q.empty()){
		int cur = q.front().first;
		long long flow = q.front().second;
		q.pop();

		for(int next : adj[cur]){
			if(parent[next] == -1 && capacity[cur][next]>0){
				parent[next]=cur;
				long long new_flow = min(flow,capacity[cur][next]);
				if(next == t)
					return new_flow;
				q.push({next,new_flow});
			}
		}
	}
	return 0;
}

long long maxFlow(int s, int t){
	long long flow=0;
	vector<int> parent(n);
	long long new_flow;

	while(new_flow = bfs(s,t,parent)){
		flow += new_flow;
		int cur = t;
		while(cur>=0 && cur != s){
			int prev = parent[cur];
			edgesAns[{prev,cur}]+=new_flow;
			capacity[prev][cur]-=new_flow;
			capacity[cur][prev]+=new_flow;
			cur=prev;
		}
	}
	return flow;
}

int main(){
	
	int m,s,t;
	
	cin >> n >> m >> s >> t;
	
	adj.assign(n,vector<int>());
	capacity.assign(n,vector<long long>(n,0));

	int a,b;
	long long c;

	while(m--){
		cin >> a >> b >> c;
		adj[a].push_back(b);
		adj[b].push_back(a);
		capacity[a][b]=c;
		capacity[b][a]=0;
	}
	long long ans = maxFlow(s,t);
	cout << n << " " << ans << " " << edgesAns.size() << endl;
	for(auto it:edgesAns){
		cout << it.first.first << " " << it.first.second << " " << it.second << endl;
	}
	return 0;
}
