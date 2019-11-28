#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<long long,long long>>> adj;
vector<bool> visited;
vector<long long> dist;
vector<long long> pos;
vector<pair<long long,long long>> A;

void dfs(long long r,long long l,long long d){
	if(pos[r]==-1)pos[r]=A.size();
	A.push_back({l,r});
	dist[r]=d;
	visited[r]=1;
	for(int i=0;i<adj[r].size();i++){
		if(!visited[adj[r][i].first]){
			dfs(adj[r][i].first,l+1,d+adj[r][i].second);
			A.push_back({l,r});
		}
	}	
}

/* Sparse table */

vector<vector<long long>> T;

void create(){
	for(long long i=0;i<A.size();i++){
		T[0][i]=i;
	}
	int s;
	for(long long i=1;(1<<i)<=A.size();i++){
		s=1<<(i-1);
		for(long long j=0;(j+(s<<1)) <= A.size();j++){
			if(A[T[i-1][j]].first < A[T[i-1][j+s]].first)
				T[i][j]=T[i-1][j];
			else
				T[i][j]=T[i-1][j+s];
		}
	}
}

long long rmq(long long a,long long b){
	long long s = (b-a)+1;
	long long k = log2(s);
	if(A[T[k][a]].first < A[T[k][(b-(1<<k))+1]].first)
		return A[T[k][a]].second;
	else
		return A[T[k][(b-(1<<k))+1]].second;
}

/***************/

int main(){
	long long n,a,b,q,lca;
	while(cin >>n){
		if(n==0)break;
		adj.assign(n,vector<pair<long long,long long>>());
		for(long long i=1;i<n;i++){
			cin >> a >> b;
			adj[i].push_back({a,b});
			adj[a].push_back({i,b});
		}
		dist.assign(n,0);
		visited.assign(n,0);
		pos.assign(n,-1);
		dfs(0,0,0);
		T.assign(log2(A.size())+1,vector<long long>(A.size(),-1));
		create();
		cin >> q;
		for(int i=0;i<q;i++){
			if(i!=0)cout << " ";
			cin >> a >> b;
			lca=rmq(min(pos[a],pos[b]),max(pos[a],pos[b]));
			//cerr << lca << " " ;
			cout << dist[a]+dist[b]-(2*dist[lca]);
		}
		cout << endl;
		A.clear();
		//for(auto u:dist)cerr/* << u.first << "->"*/ << u << " ";
	       	//cerr << endl;	
	}
	return 0;
}
