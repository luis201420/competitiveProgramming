#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int u,v,w;
};

vector<pair<int,int>> mst;
vector<Edge> edges;
vector<int> links,sizes;
long long ans;

int finds(int x){
	if(x == links[x]) return x;
	return links[x] = finds(links[x]);
}

bool same(int x, int y){
	return finds(x) == finds(y);
}

void unite(int x, int y){
	x = finds(x);
	y = finds(y);
	if(sizes[x]<sizes[y])swap(x,y);
	sizes[x]+=sizes[y];
	links[y]=x;
}

bool myComp(const Edge &e1, const Edge &e2){
	return e1.w < e2.w;
}

bool comp2(const pair<int,int> &e1, const pair<int,int> &e2){
	if(e1.first == e2.first){
		return e1.second < e2.second;
	}
	return e1.first < e2.first;
}

void kruskall(){
	sort(edges.begin(),edges.end(),myComp);
	ans=0;
	for(auto it:edges){
		if(!same(it.u,it.v)){
			unite(it.u,it.v);
			ans+=it.w;
			mst.push_back({min(it.u,it.v),max(it.u,it.v)});
		}
	}
	sort(mst.begin(),mst.end());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b,c;
	int n,m;
	while(cin >> n >> m){
		if(n == 0 && m == 0)break;
		for(int i=0;i<m;i++){
			cin >> a >> b >> c;
			edges.push_back({a,b,c});
		}
		for(int i=0;i<n;i++)links.push_back(i);
		sizes.assign(n,1);
		kruskall();
		int trees = 0;
		for(int i=0;i<n;i++){
			if(links[i] == i) trees++;
		}
		if(trees>1)cout << "Impossible" << endl;
		else{
			cout << ans << endl;
			for(auto it:mst){
				cout << it.first << " " << it.second << endl;
			}
		}
		mst.clear();
		edges.clear();
		links.clear();
	}
	return 0;
}
