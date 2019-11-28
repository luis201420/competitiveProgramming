#include <bits/stdc++.h>

using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a,b;
	int n,m;
	cin >> n >> m;
	vector<vector<bool>> g(n,vector<bool>(n,0));
	for(int i=0;i<m;i++){
		cin >> a >> b;
		g[a-1][b-1]=g[b-1][a-1]=1;
	}
	if(g[0][n-1]){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(g[i][j])g[i][j]=0;
				else g[i][j]=1;
			}
		}
	}
	vector<int> dist(n,-1);
	dist[0]=0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		a=q.front();
		q.pop();

		for(int i=0;i<n;i++){
			if(g[a][i] && dist[i]==-1){
				dist[i]=dist[a]+1;
				q.push(i);
			}
		}
	}
	cout << dist[n-1] << endl;
	return 0;
}
