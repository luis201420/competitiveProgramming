#include <bits/stdc++.h>

#define EPS 1e-9

using namespace std;

struct point{
	double x,y;
	point() { x = y = 0.0; }
	point(double _x,double _y) : x(_x),y(_y){}
};

struct line{
	double a,b,c;
};

double dist(point p1, point p2){
	return hypot(p1.x-p2.x,p1.y-p2.y);
}

void pointsToLine(point p1, point p2, line &l){
	if(fabs(p1.x-p2.x) < EPS){
		l.a = 1.0; l.b = 0.0; l.c = -p1.x;
	}
	else{
		l.a = -(double)(p1.y-p2.y) / (p1.x-p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a*p1.x) - p1.y;
	}
}

bool samePoint(point &a,point &b) {
	return (a.x==b.x)&&(a.y==b.y);
}

bool mySort(point &a, point &b){
	if(a.x == b.x) return a.y < b.y;
	else return a.x>b.x;
}

int main(){

	int cases,n;
	double a,b,res,xp;
	vector<point> points;
	line aux;

	cin >> cases;
	while(cases--){

		cin >> n;
		
		while(n--){
			cin >> a >> b;
			points.push_back(point(a,b));
		}

		sort(points.begin(),points.end(),mySort);
		
		res=0;

		for(int i=0;i<points.size();){
			int j=i+1;
			while(j<points.size()){
				if(points[j].y>points[i].y)break;
				j++;
			}
			//cerr << j << endl;
			if(j<points.size()){
				if(samePoint(points[j-1],points[i])){
					res+=dist(points[j],points[i]);
				}
				else{
					pointsToLine(points[j],points[j-1],aux);
					xp = (-(aux.b*points[i].y)-aux.c) / aux.a;
					res+=dist(points[j],point(xp,points[i].y));
				}
			}
			i=j;
		}

		printf("%.2f\n",res);
		points.clear();
	}

	return 0;
}
