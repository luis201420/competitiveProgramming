#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int u,v,w;
};

vector<Edge> edges;

vector<int> links,sizes;

int finds(int x){
	if(x == links[x])return x;
	return links[x] = finds(links[x]);
}

bool same(int x, int y){
	return finds(x) == finds(y);
}

void unite(int x, int y){
	x=finds(x);
	y=finds(y);
	if(sizes[x]<sizes[y])swap(x,y);
	sizes[x]+=sizes[y];
	links[y]=x;
}

bool myComp(const Edge &e1, const Edge &e2){
	return e1.w < e2.w;
}

int ans;

void kruskall(){
	sort(edges.begin(),edges.end(),myComp);
	for(auto it:edges){
		if(!same(it.u,it.v)){
			unite(it.u,it.v);
			ans=max(ans,it.w);
		}
	}
}

int main(){
	int n,m;
	int a,b,c;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		edges.push_back({a,b,c});
	}
	for(int i=0;i<n;i++)links.push_back(i);
	sizes.assign(n,1);
	kruskall();
	int trees = 0;
	for(int i=0;i<n;i++){
		trees+=(links[i]==i);
	}
	if(trees>1)cout << "IMPOSSIBLE" << endl;
	else{
		cout << ans << endl;
	}
	return 0;
}
