#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int u1,u2,weigth;
};

#define N 100001
#define M 17

map<int,int> valueEdges[N];
Edge edges[N<<1];


int n,m,mst;

vector<pair<int,int>> adj[N];

/********  Union Find *******************/
struct union_find
{
	int set[N];

	void init()
	{
		for(int i = 1; i <= n; i++)
			set[i] = i;
	}

	int find(const int & x)
	{
		if(set[x] == x) return x;
		return set[x] = find(set[x]);
	}

	bool join(int x, int y)
	{
		x = find(x);
		y = find(y);

		if(x == y) return 0;

		set[y] = x;
		return 1;
	}
} uf;
/*****************************************/
/************* KRUSKALL ******************/
bool operator <(const Edge &e1,const Edge &e2){
	return e1.weigth < e2.weigth;
}

void kruskall(){
	uf.init();
	sort(edges,edges+m);
	int a,b,aux=n;
	for(int i=0;i<m&&aux;i++){
		a=edges[i].u1; b=edges[i].u2;
		if(uf.join(a,b)){
			mst+=edges[i].weigth;
			//unite(a,b);
			adj[a].push_back({b,edges[i].weigth});
			adj[b].push_back({a,edges[i].weigth});
			aux--;
		}
	}
}
/*********************************************/
/***************** HLD ***********************/

int parent[N], depth[N],head[N],pos[N],road[N],rpos[N],heavy[N];

int cur_pos;

int dfs(const int &v){
	
	heavy[v]=-1;

	int size = 1,max_c_size = 0,c_size;
	for(auto & c : adj[v]){
		if(c.first != parent[v]){
			road[c.first]=c.second;
			parent[c.first]=v, depth[c.first]=depth[v]+1;
			c_size = dfs(c.first);
			size+=c_size;
			if(c_size > max_c_size)
				max_c_size = c_size, heavy[v]=c.first;
		}
	}
	return size;
}

void hld(const int &v, const int &h){
	head[v]=h, rpos[cur_pos]=v, pos[v]=cur_pos++;
	if(heavy[v]!=-1)
		hld(heavy[v],h);
	for(auto & c:adj[v]){
		if(c.first != parent[v] && c.first != heavy[v])
			hld(c.first,c.first);
	}
}

/*************** Sparse Table  ****************************/

int T[M][N];

void create(){
	for(int i=0;i<n;i++){
		T[0][i]=i;
	}
	int s,p1,p2;
	for(int i=1;(1<<i)<=n;i++){
		s=1<<(i-1);
		for(int j=0;(j+(s<<1)-1)<n;j++){
			p1=T[i-1][j];
			p2=T[i-1][j+s];
			T[i][j] = (road[rpos[p1]] > road[rpos[p2]]) ? p1 : p2;
		}
	}
}

int rmq(int a,int b){
	int s = (b-a)+1;
	int k = log2(s);
	return max(road[rpos[T[k][a]]],road[rpos[T[k][(b-(1<<k))+1]]]);
}

/**********************************************************/

int query(int a,int b){
	int res = 0,tmp;
	for(;head[a]!=head[b];b=parent[head[b]]){
		if(depth[head[a]]>depth[head[b]]) swap(a,b);
		tmp = rmq(min(pos[head[b]],pos[b]),max(pos[head[b]],pos[b]));
		res = max(res,tmp);
	}
	
	if(a==b) return res;
	
	if(depth[a] > depth[b]) swap(a,b);

	tmp = rmq(min(pos[a]+1,pos[b]),max(pos[a]+1,pos[b]));
	res = max(res,tmp);
	return res;

}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a,b,w,q;
	while(scanf("%d %d", &n, &m) != EOF){
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&w);
			valueEdges[a-1][b-1]=w;
			edges[i]={a-1,b-1,w};
		}
		mst=0;
		kruskall();
		road[0]=depth[0]=0;
		cur_pos=0;
		dfs(0);
		hld(0,0);
		create();
		scanf("%d",&q);
		while(q--){
			scanf("%d %d",&a,&b);
			printf("%d\n",mst+valueEdges[a-1][b-1]-query(a-1,b-1));
		}
		for(int i = 1; i <= n; i++)
		{
			adj[i].clear();
			valueEdges[i].clear();
		}
		//break;
	}
	return 0;
}
