#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int u,v;
	double w;
};

vector<pair<double,double>> points;
vector<Edge> edges;

double dist(int p1,int p2){
	double dx = abs (points[p1].first-points[p2].first) , dy =abs(points[p1].second-points[p2].second);
	return sqrt((dx*dx)+(dy*dy));
}

vector<int> link,sizeT;
double r1,r2,r3;

int findA(int x){
	if(x==link[x])return x;
	return link[x]=findA(link[x]);
}

bool same(int a,int b){
	return findA(a)==findA(b);
}

void unite(int a,int b){
	a=findA(a);
	b=findA(b);
	if(sizeT[a]<sizeT[b])swap(a,b);
	sizeT[a]+=sizeT[b];
	link[b]=a;
}

bool myComp(const Edge &e1,const Edge &e2){
	return e1.w<e2.w;
}

void kruskall(long long l){
	sort(edges.begin(),edges.end(),myComp);
	int a,b;
	for(auto it:edges){
		a=it.u;
		b=it.v;
		//cerr << a << " " << b << " " << it.w << endl;
		if(!same(a,b)){
			unite(a,b);
			if(it.w<=l) r1+=it.w;
			else{
				r3++;
			       	r2+=it.w;
			}
			//cerr << it.w << endl;
		}
	}
}

int main(){
	int t;
	long long n,r;
	double x,y;
	cin >> t;
	for(int c=1;c<=t;c++){
		cin >> n >> r;
		for(int i=0;i<n;i++){
			cin >> x >> y;
			points.push_back({x,y});
			for(int j=0;j<points.size()-1;j++){
				edges.push_back({i,j,dist(i,j)});
			}
		}
		sizeT.assign(n,1);
		for(int i=0;i<n;i++)link.push_back(i);
		r1=r2=r3=0;
		kruskall(r);
		cout <<"Case #"<<c<<": " << r3+1<<" "<< round(r1) << " " << round(r2) << endl;
		points.clear();
		edges.clear();
		link.clear();
	}
	return 0;
}
