#include <bits/stdc++.h>

using namespace std;

typedef pair<double,double> pdd;
typedef vector<pdd> vpdd;

vpdd points;

inline double dist(const pdd &p1, const pdd &p2){
	double dx = abs(p1.first-p2.first);
	double dy = abs(p1.second-p2.second);
	return sqrt((dx*dx)+dy*dy);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	double a,b,res=0;
	pdd pc;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		pc = {a,b};
		for(auto p:points){
			res=max(res,dist(pc,p));
		}
		points.push_back({a,b});
	}
	cout << setprecision(8) << fixed;
	cout << res << endl;
	return 0;
}
