#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> adj;
int n;

/**** HLD ****/

vector<long long> parent, depth, heavy, head, pos,rpos;
long long cur_pos;

long long dfs(int v){
	long long size = 1;
	long long max_c_size = 0,c_size;
	for(int & c : adj[v]){
		if(c != parent[v]){
			parent[c] = v, depth[c] = depth[v] + 1;
			c_size = dfs(c);
			size += c_size;
			if(c_size > max_c_size)
				max_c_size = c_size, heavy[v] = c;
		}
	}
	return size;
}

void hld(int v, int h){
	head[v] = h, rpos[cur_pos]=v, pos[v] = cur_pos++;
	if(heavy[v] != -1)
		hld(heavy[v],h);
	for(int & c: adj[v]){
		if(c != parent[v] && c != heavy[v])
			hld(c,c);
	}
}

/*********** Segment Tree *************/

#define L(i) (i<<1)+1
#define R(i) (i+1)<<1

vector<long long> tree;

void create_tree(int i,int a,int b){
	if(a==b){
		tree[i]=-1;
		return ;
	}
	int m = (a+b)/2;
	create_tree(L(i),a,m);
	create_tree(R(i),m+1,b);
	tree[i]=-1;
}

void update(int i,int a,int b,int pos){
	if(b<pos || pos<a) return;
	if(pos==a && pos==b){
		tree[i] = (tree[i]==-1)? pos : -1;
		return;
	}
	int m = (a+b)/2;
	update(L(i),a,m,pos);
	update(R(i),m+1,b,pos);
	if(tree[L(i)] == -1 && tree[R(i)] == -1){
	       	tree[i]=-1;
		return;
	}
	if(tree[L(i)] == -1){
		tree[i]=tree[R(i)];
		return;
	}
	if(tree[R(i)]==-1){
		tree[i]=tree[L(i)];
		return;
	}
	if(depth[rpos[tree[L(i)]]] < depth[rpos[tree[R(i)]]])
		tree[i]=tree[L(i)];
	else
		tree[i]=tree[R(i)];
}

int rmq(int i,int a,int b, int qa,int qb){
	if(qb < a || b < qa) return -1;
	if(qa <= a && b <=qb){
		return tree[i];
	}
	int m = (a+b)/2;
	long long r1 = rmq(L(i),a,m,qa,qb);
	long long r2 = rmq(R(i),m+1,b,qa,qb);
	
	if(r1 == -1 && r2 == -1) return -1;
	if(r1 == -1) return r2;
	if(r2==-1) return r1;

	if(depth[rpos[r1]] < depth[rpos[r2]])
		return r1;
	else
		return r2;
}

long long query(int a,int b){
	long long res=-1,tmp;
	for(;head[a]!=head[b]; b=parent[head[b]]){
		if(depth[head[a]]>depth[head[b]])swap(a,b);
		tmp = rmq(0,0,n,min(pos[head[b]],pos[b]),max(pos[head[b]],pos[b]));
		if(tmp == -1) continue;
		if(res==-1)res=tmp;
		else{
			if(depth[rpos[res]]>depth[rpos[tmp]])res=tmp;
		}
	}
	//if(a == b) return res;
	if(depth[a]>depth[b])swap(a,b);
	tmp = rmq(0,0,n,min(pos[a],pos[b]),max(pos[a],pos[b]));
	if(tmp == -1) return res;
	if(res==-1)res=tmp;
	else{
		if(depth[rpos[res]]>depth[rpos[tmp]])res=tmp;
	}
	return res;
}

inline void cal(){
	parent.resize(n);
	depth.resize(n);
	heavy.assign(n,-1);
	head.resize(n);
	pos.resize(n);
	rpos.resize(n);
	tree.assign(4*n,0);
	cur_pos = 0;

	dfs(0);
	hld(0,0);
	create_tree(0,0,n);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	long long q,a,b,aux;
	cin >> n >> q;
	adj.assign(n,vector<int>());
	for(int i=1;i<n;i++){
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	cal();
	while(q--){
		cin >> a >> b;
		if(a==0){
			update(0,0,n,pos[b-1]);
		}
		if(a==1){
			aux = query(0,b-1);
			if(aux == -1) cout << aux;
			else cout << rpos[aux]+1;
			cout << endl;
		}
	}
	cout << flush;
	return 0;
}
