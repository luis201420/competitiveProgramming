#include <bits/stdc++.h>

using namespace std;

vector<set<int>> adj;
vector<string> names;

vector<int> dfs_num,dfs_low;
stack<int> S;
vector<bool> visited;
int dfsNumberCounter;
list<list<int>> res;

void tarjanSCC(int u){
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	S.push(u);
	visited[u]=1;
	for(auto v:adj[u]){

		if(dfs_num[v] == -1)
			tarjanSCC(v);
		
		if(visited[v])
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
	}
	if(dfs_num[u] == dfs_low[u]){
		int v;
		list<int> aux;
		while(!S.empty()){
			v=S.top(); S.pop();
			visited[v]=0;
			aux.push_front(v);
			if(u==v)
				break;
		}
		res.push_front(aux);
	}
}

int main(){
	map<string,int> ids;
	int id;
	int n,m,cont=1;
	string a,b;
	while(cin >> n >> m){
		if(n==0 && m==0)break;
		S=stack<int>();
		if(cont!=1)cout << endl;
		id=1;
		adj.assign(n,set<int>());
		while(m--){
			cin >> a >> b;
			if(ids[a] == 0){
				names.push_back(a);
				ids[a]=id;
				id++;
			}
			if(ids[b] == 0){
				names.push_back(b);
				ids[b]=id;
				id++;
			}
			adj[ids[a]-1].insert(ids[b]-1);
		}
		cout << "Calling circles for data set " << cont << ":\n";
		dfs_num.assign(n,-1);
		dfs_low.assign(n,0);
		visited.assign(n,0);
		dfsNumberCounter=0;
		for(int i=0;i<n;i++){
			if(dfs_num[i]==-1)
				tarjanSCC(i);
		}
		for(auto i:res){
			for(auto j:i){
				if(j!=*(i.begin()))cout << ", ";
				cout << names[j];
			}
			cout << endl;
		}
		res.clear();
		ids.clear();
		names.clear();
		cont++;
	}
	return 0;
}
