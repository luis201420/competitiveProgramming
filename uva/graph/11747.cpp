#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int u,v,w;
};

vector<Edge> edges;
vector<int> link,sizeC,res;

int findA(int x){
	if(x == link[x]) return x;
	return link[x]=findA(link[x]);
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

void kruskal(){
	sort(edges.begin(),edges.end(),myComp);
	for(int i=0;i<edges.size();i++){
		if(!same(edges[i].u,edges[i].v)) unite(edges[i].u,edges[i].v);
		else res.push_back(edges[i].w);
	}
}

int main(){
	int n,m,a,b,c;
	while(cin >> n >> m){
		if(n==0 && m==0)break;
		for(int i=0;i<m;i++){
			cin >> a >> b >> c;
			edges.push_back({a,b,c});
		}
		for(int i=0;i<n;i++)link.push_back(i);
		sizeC.assign(n,1);
		kruskal();
		sort(res.begin(),res.end());
		for(int i=0;i<res.size();i++){
			if(i!=0)cout << " ";
			cout << res[i];
		}
		if(res.size()==0)cout << "forest";
		cout << endl;
		edges.clear();
		link.clear();
		res.clear();
	}
	return 0;
}
