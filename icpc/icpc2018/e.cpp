#include <bits/stdc++.h>

using namespace std;

struct Point{
	long long x,y;
};

bool ver_prod(Point p1,const Point &p2){
	return ((p1.x*p2.x)+(p1.y*p2.y))>=0;
}
bool ver_prodI(Point p1,const Point &p2){
	return ((p1.x*p2.x)+(p1.y*p2.y))<=0;
}

Point inver(const Point &p){
	Point res={-(p.y),p.x};
	return res;
}

int main(){
	vector<Point> ps,vs;
	long long n,a,b;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		ps.push_back({a,b});
	}

	for(int i=1;i<n;i++){
		vs.push_back({ps[i].x-ps[i-1].x,ps[i].y-ps[i-1].y});
	}

	vs.push_back({ps[0].x-ps[n-1].x,ps[0].y-ps[n-1].y});
	vector<long long> vb(n,-1),vc(n,-1);
	
	int i=1;
	while(i<vs.size() && ver_prod(inver(vs[0]),vs[i]))i++;
	vb[0]=i;
	cerr << "b "<<  i << endl;
	
	i=1;	
	while(i<vb[0] && (ver_prodI(inver(vs[i]),vs[vb[0]])||ver_prodI(inver(vs[0]),vs[i])))i++;
	cerr <<"c "<< i << endl;
	if(i!=vb[0])vc[vb[0]]=i;
	
	for(int j=1;j<vs.size();j++){
		i=vb[j-1];
		while(i<n && ver_prod(inver(vs[j]),vs[i])){
			i++;
		}
		if(i>=n)continue;
		vb[j]=i;
		cerr<<"b " << i << endl;
		i = (j+1)%n;
		while(i!=vb[j] && (ver_prodI(inver(vs[i]),vs[vb[j]]) || ver_prodI(inver(vs[j]),vs[i]))){
			i=(i+1)%n;
		}
		if(i==vb[j])continue;
		cerr <<"c "<< i << endl;
		vc[vb[j]]=i;
	}
	/*vector<int> cc(n);
	cc[n-1]=vc[n-1];
	for(int i=n-2;i>=0;i--){
		cc[i]=vc[i]+cc[i+1];
		//cerr << cc[i];
	}*/
	long long total = 0;
	/*for(int i=0;i<n;i++){
		cerr << ((vb[i]*(n-vb[i]))-cc[vb[i]]) << endl;
		total+=((vb[i]*(n-vb[i]))-cc[vb[i]]);
	}*/
	for(int i=0;i<n;i++){
		if(vb[i]==-1)continue;
		for(int j=vb[i];j<n;j++){
			if(vc[j]==-1) continue;
			for(int k=vc[j];k<vb[i];k++){
				total++;
			}
		}
	}
	cout << total << endl;
	return 0;
}
