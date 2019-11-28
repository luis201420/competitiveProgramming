#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
int n;

vector<bool> visited;
vector<int> tin, low;
int timer;
set<int> art;

void dfs(int v,int p=-1){
	visited[v]=1;
	tin[v] = low[v] = timer++;
	int children=0;
	for (int to : adj[v]) {
		if (to == p) continue;
		if (visited[to]) {
            		low[v] = min(low[v], tin[to]);
       		} else {
            		dfs(to, v);
            		low[v] = min(low[v], low[to]);
            		if (low[to] >= tin[v] && p!=-1)
                		art.insert(v);
            		++children;
        	}
    	}
    	if(p == -1 && children > 1)
        	art.insert(v);
}

void find_articulation(){
	timer = 0;
	visited.assign(n,0);
	tin.assign(n,-1);
	low.assign(n,-1);
	for(int i=0;i<n;i++){
		if(!visited[i]) dfs(i);
	}
}

int main(){
	string line,aux;
	int a,b;
	while(cin >> n){
		if(n == 0) break;
		getline(cin,line);
		adj.assign(n,vector<int>());
		while(getline(cin,line)){
			if(line == "0")break;
			int i=0;
			while(line[i]!=' ')i++;
			a = atoi(line.substr(0,i).c_str());
			i++;
			aux="";
			while(i<line.size()){
				if(line[i]!=' ')aux+=line[i];
				else{
					b = atoi(aux.c_str());
					adj[a-1].push_back(b-1);
					adj[b-1].push_back(a-1);
					aux="";
				}
				i++;
			}
			b = atoi(aux.c_str());
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1);
		}
		find_articulation();
		cout << art.size() << endl;
		art.clear();
		adj.clear();
	}
	return 0;
}
