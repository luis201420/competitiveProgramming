#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<pair<int,int>> A;
vector<int> pos;
vector<bool> visited;

/******** Sparse Table ********/

vector<vector<int>> T;

void create(){
	for(int i=0;i<A.size();i++){
		T[0][i]=i;
	}
	int s;
	for(int i=1;(1<<i)<=A.size();i++){
		s=1<<(i-1);
		for(int j=0;(j+(s<<1))<=A.size();j++){
			if(A[T[i-1][j]].first < A[T[i-1][j+s]].first)
				T[i][j]=T[i-1][j];
			else
				T[i][j]=T[i-1][j+s];
		}
	}
}

int rmq(int a,int b){
	int s = (b-a)+1;
	int k = log2(s);
	if(A[T[k][a]].first < A[T[k][(b-(1<<k)) +1]].first)
		return A[T[k][a]].second;
	else
		return A[T[k][(b-(1<<k))+1]].second;
}

/******************************/

void dfs(int r,int l){
	if(pos[r]==-1)pos[r]=A.size();
	A.push_back({l,r});
	visited[r]=1;
	for(int i=0;i<adj[r].size();i++){
		if(!visited[adj[r][i]])dfs(adj[r][i],l+1);
		A.push_back({l,r});
	}
}

int main(){
	int n,m,a,b,lca;
	cin >> n >> m;
	visited.assign(n,0);
	adj.assign(n,vector<int>());
	pos.assign(n,-1);
	for(int i=1;i<n;i++){
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	dfs(0,0);
	T.assign(log2(A.size())+1,vector<int>(A.size(),-1));
	create();
	while(m--){
		cin >> a >> b;
		b--;
		if(a==1){
		}
		else{
		}
	}
	return 0;
}
