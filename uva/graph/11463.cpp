#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dist,adj;
vector<bool> visited;
int n;

void warshall(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}

int main(){
	int t,m,a,b,res;
	cin >> t;
	for(int c=1;c<=t;c++){
		cin >> n >> m;
		dist.assign(n,vector<int>(n,1e9));
		adj.assign(n,vector<int>());
		while(m--){
			cin >> a >> b;
			dist[a][b]=1;
			dist[b][a]=1;
			dist[a][a]=dist[b][b]=0;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		warshall();
		cin >> a >> b;
		res=0;
		for(int i=0;i<n;i++){
			if(i!=a && i!=b){
				res=max(res,dist[a][i]+dist[i][b]);
			}
		}
		cout <<"Case "<<c<<": "<<res << endl;
	}
	return 0;
}
