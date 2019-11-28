#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<int,int>>> adj;

vector<int> parent,depth,heavy,head,pos,rpos,road;
int cur_pos;

int dfs(int v){
	int size = 1;
	int max_c_size = 0, c_size;
	for(auto c : adj[v]){
		if(c.first != parent[v]){
			road[c.first] = c.second;
			parent[c.first] = v , depth[c.first] = depth[v]+1;
			c_size = dfs(c.first);
			size+=c_size;
			if(c_size > max_c_size)
				max_c_size = c_size, heavy[v]=c.first;
		}
	}
	return size;
}

int decompose(int v, int h){
	head[v]=h , rpos[cur_pos]=road[v] , pos[v]=cur_pos++;
	if(heavy[v]!=-1)
		decompose(heavy[v],h);
	for(auto c : adj[v]){
		if(c.first != parent[v] && c.first != heavy[v])
			decompose(c.first,c.first);
	}
}

/***************** Segment Tree *********************/

#define L(i) (i<<1)+1
#define R(i) (i+1)<<1

vector<int> tree;

void create_tree(int i,int a,int b){
	if(a==b){
		tree[i]=rpos[a];
		return ;
	}
	int m = (a+b)/2;
	create_tree(L(i),a,m);
	create_tree(R(i),m+1,b);
	tree[i] = max(tree[L(i)],tree[R(i)]);
}

void update(int i,int ua,int a,int b,int v){
	if(b < ua || ua < a) return;
	if(a==ua && ua==b){
		tree[i]=v;
		return;
	}
	int m = (a+b)/2;
	update(L(i),ua,a,m,v);
	update(R(i),ua,m+1,b,v);
	tree[i]=max(tree[L(i)],tree[R(i)]);
}

int rmq(int i,int a,int b, int qa ,int qb){
	if(qb < a || b < qa) return 0;
	if(qa<= a && b <=qb){
		return tree[i];
	}
	int m = (a+b)/2;
	int r1 = rmq(L(i),a,m,qa,qb);
	int r2 = rmq(R(i),m+1,b,qa,qb);
	return max(r1,r2);
}

int query(int a ,int b){
	int res = 0,tmp;
	for(; head[a] != head[b] ; b=parent[head[b]]){
		if(depth[head[a]]> depth[head[b]])swap(a,b);
		tmp = rmq(0,0,n,min(pos[head[b]],pos[b]),max(pos[head[b]],pos[b]));
		res = max(res,tmp);
	}
	if(a == b) return res;
	if(depth[a] > depth[b]) swap(a,b);
	tmp = rmq(0,0,n,min(pos[a]+1,pos[b]),max(pos[a]+1,pos[b]));
	res = max(res,tmp);
	return res;
}

void init(){
	parent.resize(n);
	depth.resize(n);
	heavy.assign(n,-1);
	head.resize(n);
	pos.resize(n);
	rpos.resize(n);
	road.resize(n);
	tree.assign(4*n,0);
	cur_pos=0;
	road[0] = 0;
	
	dfs(0);
	decompose(0,0);
	create_tree(0,0,n);
}

int main(){
	ios_base::sync_with_stdio(false);   cin.tie(0)  ;
	vector<pair<int,int>> edges;
	int t,a,b,w,r;
	pair<int,int> aux;
	string ins;
	cin >> t;
	for(int k=0;k<t;k++){
		if(k!=0)cout << endl;
		cin >> n;
		adj.assign(n,vector<pair<int,int>>());
		for(int i=0;i<(n-1);i++){
			cin >> a >> b >> w;
			edges.push_back({a-1,b-1});
			adj[a-1].push_back({b-1,w});
			adj[b-1].push_back({a-1,w});
		}
		init();
		while(cin >> ins){
			if(ins == "DONE")break;
			cin >> a >> b;
			if(ins == "QUERY"){
				cout << query(a-1,b-1) << endl;
			}
			if(ins == "CHANGE"){
				aux = edges[a-1];
				r = depth[aux.first]<depth[aux.second]?aux.second : aux.first;
				update(0,pos[r],0,n,b);
			}
		}
		edges.clear();
	}
	return 0;
}
