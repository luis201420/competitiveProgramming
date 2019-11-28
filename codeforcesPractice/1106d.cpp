#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
vector<int> ans;

void bfs(int r){
	visited[r]=1;
	priority_queue<int> q;
	q.push(0);
	int u,v;
	while(!q.empty()){
		u=-q.top();
		ans.push_back(u+1);
		q.pop();
		for(int i=0;i<graph[u].size();i++){
			v=graph[u][i];
			if(!visited[v]){
				visited[v]=1;
				q.push(-v);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,a,b;
	cin >> n >> m;
	graph.assign(n,vector<int>());
	for(int i=0;i<m;i++){
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	visited.assign(n,0);
	bfs(0);
	for(int i=0;i<ans.size();i++){
		if(i!=0) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
