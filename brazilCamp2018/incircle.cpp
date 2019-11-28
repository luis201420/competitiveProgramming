#include <bits/stdc++.h>

using namespace std;

struct TPoint{
	double x,y;
};

double dist(const TPoint &a,const TPoint & b){
	double dx = abs(a.x-b.x);
	double dy = abs(a.y-b.y);
	return sqrt((dx*dx)+(dy*dy));
}

int main(){
	double x1,y1,x2,y2,x3,y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	TPoint p1 = {x1,y1};
	TPoint p2 = {x2,y2};
	TPoint p3 = {x3,y3};
	double a = dist(p1,p2);
	double b = dist(p2,p3);
	double c = dist(p3,p1);
	double s = (a+b+c)/2.0;
	double rx = ((p1.x*b)+(p2.x*c)+(p3.x*a))/(a+b+c);
	double ry = ((p1.y*b)+(p2.y*c)+(p3.y*a))/(a+b+c);
	double r = sqrt(s*(s-a)*(s-b)*(s-c))/s;
	cout << setprecision(4) << fixed;
	cout << rx << " " << ry << " " << r << endl;
	return 0;
}
