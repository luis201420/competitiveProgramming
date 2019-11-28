#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> dist;
vector<vector<int>> adj;
int n;

void bfs(int r){
	queue<int> q;
	q.push(r);
	dist.assign(n,1e9);
	dist[r]=0;
	int v;
	while(!q.empty()){
		v=q.front();
		q.pop();
		for(int i=0;i<adj[v].size();i++){
			if(dist[adj[v][i]]==1e9){
				dist[adj[v][i]]=dist[v]+1;
				q.push(adj[v][i]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t,m,a,b;
	cin >> t;
	vector<int> odd,even;
	while(t--){
		cin >> n >> m;
		adj.assign(n,vector<int>());
		while(m--){
			cin >> a >> b;
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1);
		}
		bfs(0);
		for(int i=0;i<n;i++){
			if(dist[i]&1)odd.push_back(i+1);
			else even.push_back(i+1);
		}
		if(odd.size() < even.size()){
			cout << odd.size() << endl;
			for(int i=0;i<odd.size();i++){
				if(i!=0)cout << " ";
				cout << odd[i];
			}
			cout << endl;
		}
		else{
			cout << even.size() << endl;
			for(int i=0;i<even.size();i++){
				if(i!=0)cout << " ";
				cout << even[i];
			}
			cout << endl;
		}
		odd.clear();
		even.clear();
	}
	return 0;
}
