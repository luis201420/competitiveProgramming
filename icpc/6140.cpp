#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<pair<int,int>> h;
vector<bool> ver;
vector<int> pos;

/** Sparse Table  **/
/*******************/
vector<vector<int>> T;

void create(){
	for(int i=0;i<h.size();i++){
		T[0][i]=i;
	}
	int s;
	for(int i=1;(1<<i)<=h.size();i++){
		s=1<<(i-1);
		for(int j=0;(j+(s<<1))<=h.size();j++){
			if(h[T[i-1][j]].first < h[T[i-1][j+s]].first)
				T[i][j]=T[i-1][j];
			else
				T[i][j]=T[i-1][j+s];
		}
	}
}

int rmq(int a,int b){
	int s = (b-a)+1;
	int k = log2(s);
	if(h[T[k][a]].first < h[T[k][(b-(1<<k)) +1]].first)
		return h[T[k][a]].second;
	else
		return h[T[k][(b-(1<<k)) +1]].second;
}
/*******************/

void dfs(int r,int l){
	if(pos[r]==-1)pos[r]=h.size();
	if(level[r]==-1)level[r]=l;
	h.push_back({l,r});
	for(int i=0;i<adj[r].size();i++){
		dfs(adj[r][i],l+1);
		h.push_back({l,r});
	}

}

int main(){
	int n,f;
	while(cin >> n){
		adj.assign(n,vector<int>());
		ver.assign(n,1);
		pos.assign(n,-1);
		for(int j=0;j<n;j++){
			cin >> f;
			adj[j].push_back(f-1);
		}
		for(int j=0;j<n;j++){
			if(ver[j]){
				dfs(j,0);
				break;
			}
		}
		T.assign(log2(h.size())+1,vector<int>(h.size(),-1));
		create();
		cin >> q;
		cout << "Case "<<i <<":\n";
		while(q--){
			cin >> a >> b;
			cout << rmq(min(pos[a-1],pos[b-1]),max(pos[a-1],pos[b-1]))+1 <<endl;
		}
		//for(int j=0;j<h.size();j++)cerr << h[j].second << "->" << h[j].first << " / ";
		//cerr << endl;
		h.clear();
	}
	return 0;
}

