#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int v,w,l;
};

vector<Edge> adj;
vector<int> MST;
int sets;

/***** Union-Find ******/

vector<int> link,size;

int find(int x){
	if(x==link[x])return x;
	return link[x]=find(link[x]);
}

bool same(int x,int y){
	return find(x)==find(y);
}

void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(size[x]<size[y])swap(x,y);
	size[x]+=size[y];
	link[y]=x;
	sets--;
}

/***** Kruskall *****/

bool myComp(const Edge &e1,const Edge &e2){
	return e1.l<e2.l;
}

void kruskall(){
	Edge u;	
	for(int i=0;i<adj.size();i++){
		u=adj[i];
		if(!same(u.v,u.w)){
			unite(u.v,u.w);
			MST.push_back(i);
		}	
	}
}

long long second_MST(int id){
	long long r=0;
	Edge u;
	for(int i=0;i<adj.size();i++){
		if(i==id)continue;
		u=adj[i];
		if(!same(u.v,u.w)){
			unite(u.v,u.w);
			r+=u.l;
		}	
	}
	if(sets!=1)return 1e9;
	return r;
}

int main(){
	int t,n,m;
	int a,b,c;
	long long s1,s2;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i=0;i<m;i++){
			cin >> a >> b >> c;
			adj.push_back({a-1,b-1,c});
		}
		sort(adj.begin(),adj.end(),myComp);
		size.assign(n,1);
		for(int i=0;i<n;i++)link.push_back(i);
		kruskall();
		s2=1e9;
		s1=0;
		for(int it:MST){
			link.clear();
			for(int i=0;i<n;i++)link.push_back(i);
			size.assign(n,1);
			sets=n;

			s2=min(s2,second_MST(it));
			s1+=adj[it].l;
		}
		if(s2==1e9)s2=s1;
		cout << s1 << " " << s2 << endl;
		adj.clear();
		link.clear();
		MST.clear();
	}
	return 0;
}
