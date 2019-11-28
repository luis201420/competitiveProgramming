#include<bits/stdc++.h>

using namespace std;

vector<int> degree;
vector<vector<bool>> ans;
vector<vector<int>> adj;
vector<pair<int,int>> edges;
int n,m;
bool ver;

void bfs(){
	vector<bool> visited(n,0);
	queue<pair<pair<int,int>,int>> q;
	q.push({{0,0},-1});
	visited[0]=1;
	int u,l,p;
	while(!q.empty()){
		u=q.front().first.first; l=q.front().first.second; p=q.front().second;
		cerr << u << " " << p << endl;
		q.pop();
		if(l!=0){
			ans[p][u]=!(l&1);
			ans[u][p]=l&1;
			if(ans[p][u] && degree[p]>1)ver=0;
			if(ans[u][p] && degree[u]>1)ver=0;
			degree[u]+=(!l&1);
			degree[p]+=(l&1);
		}
		for(int i=0;i<adj[u].size();i++){
			if(!visited[adj[u][i]]){
				visited[adj[u][i]]=1;
				q.push({{adj[u][i],l+1},u});
			}
		}
	}
}

int main(){
	int a,b;
	cin >> n >> m;
	degree.assign(n,0);
	ans.assign(n,vector<bool>(n,0));
	adj.assign(n,vector<int>());
	for(int i=0;i<m;i++){
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
		edges.push_back({a-1,b-1});
		ans[a-1][b-1]=1;
	}
	ver=1;
	bfs();
	if(!ver)cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		int aux1,aux2;
		for(int i=0;i<edges.size();i++){
			aux1=edges[i].first;
			aux2=edges[i].second;
			if(!ans[aux1][aux2])cout << 1;
			else cout << 0;
			//cout << ans[edges[i].first][edges[i].second];
		}
		cout << endl;
	}
	return 0;
}
