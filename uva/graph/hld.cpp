#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<int> parent, depth, heavy, head, pos,road,rpos;
int cur_pos;
int n;

int dfs(int v){
	int size = 1;
	int max_c_size = 0;
	for(auto c : adj[v]){
		if(c.first != parent[v]){
			road[c.first] = c.second;
			parent[c.first] = v, depth[c.first] = depth[v] + 1;
			int c_size = dfs(c.first);
			size += c_size;
			if(c_size > max_c_size)
				max_c_size = c_size, heavy[v] = c.first;
		}
	}
	return size;
}

int decompose(int v, int h){
	head[v] = h, rpos[cur_pos]=v, pos[v] = cur_pos++;
	if(heavy[v] !=-1)
		decompose(heavy[v],h);
	for(auto c : adj[v]){
		if(c.first != parent[v] && c.first != heavy[v])
			decompose(c.first,c.first);
	}
}

/************* Sparse Table ************************/

vector<vector<int>> min_T,max_T;

void create(){
	for(int i=0;i<n;i++){
		min_T[0][i]=i;
		max_T[0][i]=i;
	}
	int s,x,y;
	for(int i=1;(1<<i)<=n;i++){
		s = 1<<(i-1);
		for(int j=0;(j+(s<<1))<=n;j++){
			x = min_T[i-1][j];
			y = min_T[i-1][j+s];
			min_T[i][j] = road[rpos[x]] < road[rpos[y]] ? x : y;

			x = max_T[i-1][j];
			y = max_T[i-1][j+s];
			max_T[i][j] = road[rpos[x]] > road[rpos[y]] ? x : y;
		}
	}
}

int res_max,res_min;

void rmq(int a,int b){
	int s = (b-a)+1;
	int k = log2(s);
	int x = max_T[k][a];
	int y = max_T[k][(b-(1<<k))+1];
	res_max = max(road[rpos[x]],road[rpos[y]]);
	x = min_T[k][a];
	y = min_T[k][(b-(1<<k))+1];
	res_min = min(road[rpos[x]],road[rpos[y]]);
}

int rmin,rmax;
void query(int a ,int b){
	rmax = 0 ; rmin = 1e9;
	for(;head[a]!=head[b];b=parent[head[b]]){
		if(depth[head[a]] > depth[head[b]]) swap(a,b);
		rmq(min(pos[head[b]],pos[b]),max(pos[head[b]],pos[b]));
		rmin = min(rmin,res_min);
		rmax = max(rmax,res_max);
	}

	if(a==b) return;

	if(depth[a] > depth[b]) swap(a,b);
	rmq(min(pos[a]+1,pos[b]),max(pos[a]+1,pos[b]));
	rmin = min(rmin,res_min);
	rmax = max(rmax,res_max);
}

void cal(){
	parent = vector<int>(n);
	depth = vector<int>(n);
	heavy = vector<int>(n,-1);
	head = vector<int>(n);
	pos = vector<int>(n);
	rpos = vector<int>(n);
	min_T.assign(log2(n)+1,vector<int>(n,-1));
	max_T.assign(log2(n)+1,vector<int>(n,-1));
	cur_pos = 0;
	dfs(0);
	decompose(0,0);
	create();
}

int main(){
	int a,b,w,q;
	cin >> n;
	adj.assign(n,vector<pair<int,int>>());
	road.assign(n,0);
	for(int i=0;i<(n-1);i++){
		cin >> a >> b >> w;
		adj[a-1].push_back({b-1,w});
		adj[b-1].push_back({a-1,w});
	}
	cal();
	cin >> q;
	for(int i=0;i<q;i++){
		cin >> a >> b;
		query(a-1,b-1);
		cout << rmin << " " << rmax << endl;
	}
	return 0;
}
