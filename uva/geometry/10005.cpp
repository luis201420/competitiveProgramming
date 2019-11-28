#include <bits/stdc++.h>

using namespace std;

struct point{
	double x,y;
	point(){x = y = 0.0;}
	point(double _x,double _y) : x(_x), y(_y) {}
};

bool circle2PtsRad(point p1, point p2, double r, point &c){
	double d2 = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
	double det = r * r / d2 - 0.25;
	if(det<0.0) return 0;
	double h = sqrt(det);
	c.x = (p1.x+p2.x)*0.5 + (p1.y-p2.y)*h;
	c.y = (p1.y+p2.y)*0.5 + (p2.x-p1.x)*h;
	return 1;
}

double dist(point p1,point p2){
	return hypot(p1.x-p2.x,p1.y-p2.y);
}

int main(){
	int v;
	double a,b,r;
	vector<point> points;
	point c1,c2;
	bool  v1,v2,res;

	while(cin >> v){
		if(v==0)break;
		while(v--){
			cin >> a >> b;
			points.push_back(point(a,b));
		}
	
		cin >> r;
	
		res = false;

		for(int i=0;i<points.size();i++){
			for(int j=i+1;j<points.size();j++){
				v1 = circle2PtsRad(points[i],points[j],r,c1);
				v2 = circle2PtsRad(points[j],points[i],r,c2);
				
				for(int k=0;k<points.size();k++){
					if(v1){
						v1 &= (r>=dist(points[k],c1));
					}
					if(v2){
						v2 &= (r>=dist(points[k],c2));
					}
				}
				if(v1 || v2) {
					res=true;
					break;
				}
			}
			if(res)break;
		}

		if(res) cout << "The polygon can be packed in the circle.";
		else cout << "There is no way of packing that polygon.";

		cout << endl;
		points.clear();
	}
}
