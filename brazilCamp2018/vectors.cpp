#include<bits/stdc++.h>

using namespace std;

struct TVector{
	double x,y;
	TVector operator+(TVector q)const{
		return {x+q.x,y+q.y};
	}
	double len(){
		return sqrt((x*x)+(y*y));
	}
};

double dotProduct(const TVector &a,const TVector &b){
	return (a.x*b.x)+(a.y*b.y);
}

double crossProduct(const TVector &a, const TVector &b){
	return (a.x*b.y)-(a.y*b.x);
}

int main(){
	double x01,y01,xf1,yf1;
	double x02,y02,xf2,yf2;
	cin >> x01 >> y01 >> xf1 >> yf1;
	cin >> x02 >> y02 >> xf2 >> yf2;
	TVector v1 = {xf1-x01,yf1-y01};
	TVector v2 = {xf2-x02,yf2-y02};
	cout << setprecision(9) <<fixed;
	cout << v1.len() <<" " << v2.len()<< endl;
	TVector s = v1+v2;
	cout << s.x << " " << s.y << endl;
	cout << dotProduct(v1,v2) << " "<< crossProduct(v1,v2) << endl;
	cout << abs(crossProduct(v1,v2))/2.0 << endl;
	return 0;
}
