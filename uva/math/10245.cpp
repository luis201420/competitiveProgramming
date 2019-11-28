#include <bits/stdc++.h>

using namespace std;

struct Point{
	double x,y;
};

double dist(const Point &a,const Point &b){
	double d1 = abs(a.x-b.x);
	double d2 = abs(a.y-b.y);
	return sqrt((d1*d1) + (d2*d2));
}

int main(){
	int n;
	double p1,p2,res;
	vector<Point> ps;
	Point cur;
	cout << setprecision(4) << fixed;
	while(cin>>n){
		if(n==0)break;
		res = 1e9;
		while(n--){
			cin >> p1 >> p2;
			cur = {p1,p2};
			for(int i=0;i<ps.size();i++){
				res=min(res,dist(cur,ps[i]));
			}
			ps.push_back(cur);
		}
		if(res >= 10000)cout << "INFINITY";
		else cout << res ;
		cout << endl;
		ps.clear();
	}
	return 0;
}
