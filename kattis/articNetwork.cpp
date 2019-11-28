#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int u,v;
	double w;
};

vector<Edge> edges;
vector<int> links,sizes;
vector<double> ans;

int finds(int x){
	if(x == links[x]) return x;
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

void kruskall(){
	sort(edges.begin(),edges.end(),myComp);
	for(auto it:edges){
		if(!same(it.u,it.v)){
			unite(it.u,it.v);
			ans.push_back(it.w);
		}
	}
}

double dist(const pair<double,double> &p1, const pair<double,double> &p2){
	double dx = abs(p1.first-p2.first);
	double dy = abs(p1.second-p2.second);
	return sqrt((dx*dx)+(dy*dy));
}

int main(){
	int t,s,p;
	double a,b;
	cin >> t;
	vector<pair<double,double>> ps;
	pair<double,double> aux;
	cout << setprecision(2) << fixed;
	while(t--){
		cin >> s >> p;
		for(int i=0;i<p;i++){
			cin >> a >> b;
			aux={a,b};
			for(int j=0;j<ps.size();j++){
				edges.push_back({i,j,dist(aux,ps[j])});
			}
			ps.push_back(aux);
		}
		for(int i=0;i<p;i++)links.push_back(i);
		sizes.assign(p,1);
		kruskall();
		sort(ans.begin(),ans.end(),greater<double>());
		cout << ans[s-1] << endl;
		
		links.clear();
		ps.clear();
		edges.clear();
		ans.clear();
	}
	return 0;
}
