#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int u,v;
	double w;
};

double ans;
vector<Edge> edges;

double dist(double x1,double y1,double x2,double y2){
	double dx = abs(x1-x2);
	double dy = abs(y1-y2);
	return sqrt((dx*dx)+dy*dy);
}

/********** UNION FIND *****************/

vector<int> links,sizes;
int findU(int x){
	if(x == links[x])return x;
	return links[x]=findU(links[x]);
}
bool same(int x,int y){
	return findU(x)==findU(y);
}
void unite(int x,int y){
	x = findU(x);
	y = findU(y);
	if(sizes[x]<sizes[y])swap(x,y);
	sizes[x]+=sizes[y];
	links[y]=x;
}

/***************************************/

bool myComp(const Edge &e1,const Edge &e2){
	return e1.w < e2.w;
}

void kruskall(){
	sort(edges.begin(),edges.end(),myComp);
	for(auto it:edges){
		if(!same(it.u,it.v)){
			unite(it.u,it.v);
			ans+=it.w;
		}	
	}
}


int main(){
	int n,m;
	double a,b;
	vector<pair<double,double>> all;
	cout << setprecision(10) << fixed;
	cin >> n;
	while(n--){
		cin >> m;
		for(int i=0;i<m;i++)links.push_back(i);
		sizes.assign(m,1);
		for(int j=0;j<m;j++){
			cin >> a >> b;
			for(int i=0;i<all.size();i++){
				edges.push_back({i,int(all.size()),dist(a,b,all[i].first,all[i].second)});
			}
			all.push_back({a,b});
		}
		ans = 0;

		kruskall();

		cout << ans << endl;
		links.clear();
		edges.clear();
		all.clear();
	}
	return 0;
}
