#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist;
int n,m;

void dijkstra(){
	priority_queue<pair<int,int>> q;
	dist[0] = adj[0][0];
	q.push({0,0});
	pair<int,int> posC;
	int b,w;
	while(!q.empty()){
		int a=q.top().second; q.pop();
		if(visited[a]) continue;
		visited[a]=1;
		posC = { a/m , a%m };
		if((posC.second-1)>=0){
			b = (posC.first*m)+(posC.second-1);
			w = adj[posC.first][posC.second-1];
			if(dist[a]+w < dist[b]){
				dist[b]=dist[a]+w;
				q.push({-(dist[b]),b});
			}
		}
		if((posC.second+1)<m){
			b = (posC.first*m)+(posC.second+1);
			w = adj[posC.first][posC.second+1];
			if(dist[a]+w < dist[b]){
				dist[b]=dist[a]+w;
				q.push({-(dist[b]),b});
			}
		}
		if((posC.first-1)>=0){
			b = ((posC.first-1)*m)+posC.second;
			w = adj[posC.first-1][posC.second];
			if(dist[a]+w < dist[b]){
				dist[b]=dist[a]+w;
				q.push({-(dist[b]),b});
			}
		}
		if((posC.first+1)<n){
			b = ((posC.first+1)*m)+posC.second;
			w = adj[posC.first+1][posC.second];
			if(dist[a]+w < dist[b]){
				dist[b]=dist[a]+w;
				q.push({-(dist[b]),b});
			}
		}
	}
}

int main(){
	int t,v,pos;
	while(cin >> t){
		while(t--){
			cin >> n >> m;
			adj.assign(n,vector<int>(m,0));
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cin >> v;
					adj[i][j]=v;
				}
			}
			dist.assign((n*m),1e9);
			visited.assign((n*m),0);
			dijkstra();
			cout << dist[(n*m)-1] << endl;
		}
	}
	return 0;
}
