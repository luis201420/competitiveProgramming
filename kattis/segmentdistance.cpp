#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

typedef double Real;
typedef pair<Real,Real> point;

Real dist(point &p1,point &p2){
	Real dX = abs(p1.X-p2.X);
	Real dY = abs(p1.Y-p2.Y);
	return sqrt((dX*dX)+(dY*dY));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	point p1,p2,p3,p4;
	Real d1,d2,d3,d4;
	while(n--){
		cin >> p1.X >> p1.Y >> p2.X >> p2.Y >> p3.X >> p3.Y >> p4.X >> p4.Y; 
		d1 = dist(p1,p3);
		d2 = dist(p1,p4);
		d3 = dist(p2,p3);
		d4 = dist(p2,p4);
		cout << min(d1,min(d2,min(d3,d4))) << "\n";
	}
	return 0;
}
