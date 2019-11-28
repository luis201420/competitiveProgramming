#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>  adj;

vector<pair<int,int>> art;
set<int> art_id;
vector<bool> visited,art_ver;
vector<int> tin,low;
int timer;
int n,m;

void dfs(int v,int p=-1){
	visited[v]=1;
	tin[v] = low[v] = timer++;
	int children = 0;
	for(int to : adj[v]){
		if(to == p) continue;
		if(visited[to]){
			low[v] = min(low[v],tin[to]);
		}
		else{
			dfs(to,v);
			low[v] = min(low[v],low[to]);
			if(low[to] >= tin[v] && p!=-1){
				art_ver[v]=1;
				art_id.insert(v);
			}
			++children;
		}
	}
	if( p==-1  && children > 1){
		art_ver[v]=1;
		art_id.insert(v);
	}
}

void find_articulation(){
	timer = 0;
	visited.assign(n,0);
	tin.assign(n,-1);
	low.assign(n,-1);
	art_ver.assign(n,0);
	for(int i=0;i<n;++i){
		if(!visited[i])
			dfs(i);
	}
}

bool myComp(const pair<int,int>& p1,const pair<int,int>& p2){
	if(p1.second == p2.second){
		return p1.first < p2.first;
	}
	return p1.second > p2.second;
}

void dfs_C(int r){
	visited[r]=1;
	for(int i : adj[r]){
		if(!visited[i])
			dfs_C(i);
	}
}

int main(){
	int cont;
	int a,b,aux;
	while(cin >> n >> m){
		if((n+m)==0) break;
		aux=m;
		adj.assign(n,vector<int>());
		while(cin >> a >> b){
			if(a==-1 && b==-1)break;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		//cerr << "a" << endl;
		find_articulation();
		//cerr << "b" << endl;
		for(auto u:art_id){
			cont = 0;
			visited.assign(n,0);
			visited[u]=1;
			for(int i=0;i<n;i++){
				if(!visited[i]){
					dfs_C(i);
					cont++;
				}
			}
			art.push_back({u,cont});
		}
		m-=art_id.size();
		for(int i=0;i<n && m>0;i++){
			if(art_ver[i])continue;
			else{
				art.push_back({i,1});
				m--;
			}
		}
		sort(art.begin(),art.end(),myComp);
		m=aux;
		for(int i=0;i<m;i++){
			cout<< art[i].first << " " << art[i].second << endl;
		}
		art.clear();
		art_id.clear();
		cout << endl;
	}
	return 0;
}
