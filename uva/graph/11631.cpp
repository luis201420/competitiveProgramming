#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int u,v,w;
};

vector<Edge> edges;
vector<int> link,sizeC;

int findA(int x){
	if(x == link[x]) return x;
	return link[x] = findA(link[x]);
}

bool same(int x,int y){
	return findA(x) == findA(y);
}

void unite(int x,int y){
	x=findA(x);
	y=findA(y);
	if(sizeC[x]<sizeC[y])swap(x,y);
	sizeC[x]+=sizeC[y];
	link[y]=x;
}

bool myComp(const Edge &e1,const Edge &e2){
	return e1.w < e2.w;
}

long long kruskal(){
	long long res = 0;
	sort(edges.begin(),edges.end(),myComp);
	for(int i=0;i<edges.size();i++){
		if(!same(edges[i].u,edges[i].v))unite(edges[i].u,edges[i].v);
		else res+=edges[i].w;
	}
	return res;
}

int main(){
	int n,m,a,b,c;
	while(cin >> m >> n){
		if(m==0 && n==0) break;
		for(int i=0;i<n;i++){
			cin >> a >> b >> c;
			edges.push_back({a,b,c});
		}
		for(int i=0;i<m;i++)link.push_back(i);
		sizeC.assign(m,1);
		cout << kruskal() << endl;
		link.clear();
		edges.clear();
	}
	return 0;
}
