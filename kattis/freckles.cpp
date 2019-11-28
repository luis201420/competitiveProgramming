#include <bits/stdc++.h>

using namespace std;

double dist(const pair<double,double> &p1,const pair<double,double> &p2){
	double dx = abs(p1.first-p2.first);
	double dy = abs(p1.second-p2.second);
	return sqrt((dx*dx)+(dy*dy));
}

struct Edge{
	int u,v;
	double w;
};
vector<Edge> edges;

double ans;

vector<int> links,sizes;

int finds(int x){
	if(x == links[x]) return x;
	return links[x] = finds(links[x]);
}

bool same(int x, int y){
	return finds(x)==finds(y);
}

void unite(int x, int y){
	x=finds(x);
	y=finds(y);
	if(sizes[x]<sizes[y])swap(x,y);
	sizes[x]+=sizes[y];
	links[y]=x;
}

bool mycomp(const Edge &e1, const Edge &e2){
	return e1.w < e2.w;
}

void kruskall(){
	sort(edges.begin(),edges.end(),mycomp);
	for(auto it:edges){
		if(!same(it.u,it.v)){
			unite(it.u,it.v);
			ans+=it.w;
			//cerr << it.w << endl;
		}
	}
}

int main(){

	cout << setprecision(2) << fixed;
	int t,n;
	double a,b;
	cin >> t;
	pair<double,double> aux;
	vector<pair<double,double>> ps;
	for(int k=0;k<t;k++){
		if(k!=0)cout << endl;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> a >> b;
			aux={a,b};
			for(int j=0;j<ps.size();j++){
				edges.push_back({i,j,dist(aux,ps[j])});
			}
			ps.push_back({a,b});
		}
		ans=0;
		for(int i=0;i<n;i++)links.push_back(i);
		sizes.assign(n,1);
		kruskall();
		cout << ans << endl;
		
		links.clear();
		ps.clear();
		edges.clear();
	}
	return 0;
}
