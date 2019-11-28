#include <bits/stdc++.h>

using namespace std;

double dist(double x1, double y1, double x2,double y2){
	double dx = abs(x1-x2);
	double dy = abs(y1-y2);
	return sqrt((dx*dx)+(dy*dy));
}

int main(){
	double x,y,x1,y1,x2,y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	
	double res;
	
	if(x<x1 && y>y2){
		res=dist(x,y,x1,y2);
	}
	else if(x<x1 && y<y1){
		res=dist(x,y,x1,y1);
	}
	else if(x>x2 && y>y2){
		res=dist(x,y,x2,y2);
	}
	else if(x>x2 &&y<y1){
		res=dist(x,y,x2,y1);
	}
	else{
		if(x1<=x && x <=x2 && y>y2){
			res=y-y2;
		}
		else if(x1<=x && x <=x2 && y<y1){
			res=y1-y;
		}
		else if(y1<=y && y<=y2 && x<x1){
			res=x1-x;
		}
		else if(y1<=y && y<=y2 && x>x2){
			res=x-x2;
		}

	}
	printf("%.3f\n", res);
	return 0;
}
