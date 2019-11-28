#include <bits/stdc++.h>

using namespace std;

struct Edge{
	long long u,v,w;
};

vector<Edge> edges;
vector<long long>  link,sizeC;

int findL(int x){
	if(x==link[x]) return x;
	return link[x]=findL(link[x]);
}

bool same(int x,int y){
	return findL(x) == findL(y);
}

void unite(int x,int y){
	x=findL(x);
	y=findL(y);
	//cerr << "/" << x << " " << y << endl;
	if(sizeC[x]<sizeC[y]) swap(x,y);
	sizeC[x]+=sizeC[y];
	link[y]=x;
}

bool myComp(const Edge &e1, const Edge &e2){
	return e1.w < e2.w;
}

long long kruskall(){
	long long res=0;
	sort(edges.begin(),edges.end(),myComp);
	for(int i=0;i<edges.size();i++){
		//cerr << edges[i].u << " " << edges[i].v << endl;
		if(!same(edges[i].u,edges[i].v))unite(edges[i].u,edges[i].v);
		else res+=edges[i].w;
	}
	return res;
}

int main(){
	long long n,c,r,a,b,p;
	cin >> n;
	while(n--){
		cin >> c >> r;
		for(int i=0;i<r;i++){
			cin >> a >> b >> p;
			edges.push_back({a,b,p});
		}
		for(int i=0;i<c;i++)link.push_back(i);
		sizeC.assign(c,1);
		cout << kruskall() << endl;
		edges.clear();
		link.clear();
	}
	return 0;
}
