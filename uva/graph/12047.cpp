#include <bits/stdc++.h>

using namespace std;

vector<bool> procesed;
vector<vector<long long>> dist;
long long n,m,s,t,p,maxToll;

vector<vector<pair<long long,long long>>> adj[2];

void dijkstra(long long ini,long long id){
	procesed.assign(n,0);
	priority_queue<pair<long long,long long>> q;
	dist[id][ini]=0;
	q.push({0,ini});
	long long a,b,w;
	while(!q.empty()){
		a = q.top().second;q.pop();
		if(procesed[a])continue;
		procesed[a]=1;
		for(auto u:adj[id][a]){
			b=u.first,w=u.second;
			if((dist[id][a]+w) < dist[id][b]){
				dist[id][b]=dist[id][a]+w;
				q.push({-dist[id][b],b});
			}
		}
	}
}

int main(){
	int cases;
	long long x,y,z;
	cin >> cases;
	while(cases--){
		cin >> n >> m >> s >> t >> p;
		adj[0].assign(n,vector<pair<long long,long long>>());
		adj[1]=adj[0];
		while(m--){
			cin >> x >> y >> z;
			adj[0][x-1].push_back({y-1,z});
			adj[1][y-1].push_back({x-1,z});
		}
		s--;
		t--;
		dist.assign(2,vector<long long>(n,1e9));
		dijkstra(s,0);
		dijkstra(t,1);
		maxToll=-1;
		for(int i=0;i<adj[0].size();i++){
			for(int j=0;j<adj[0][i].size();j++){
				//cerr << i << " " << adj[i][j].first << endl;
				//cerr << dist[0][i] << " " << dist[1][adj[i][j].first] << endl;
				if((dist[0][i]+adj[0][i][j].second+dist[1][adj[0][i][j].first])<=p){
					maxToll=max(maxToll,adj[0][i][j].second);
				}
			}
		}
		cout <<maxToll<<endl;
	}
	return 0;
}
