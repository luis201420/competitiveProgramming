#include <bits/stdc++.h>

using namespace std;

int week[7] = {1,2,3,1,3,2,1};

int res;

void cal(int x, int y, int z,int d){
	if(week[d]==1)x--;
	if(week[d]==2)y--;
	if(week[d]==3)z--;
	if(x<0 || y<0 || z<0)return;
	res++;
	cal(x,y,z,(d+1)%7);
}

int main(){
	int a,b,c;
	cin >> a >> b >> c;

	int m;
	m = min(a/3,min(b/2,c/2));
	/*if(a<=b && a<=c){
		m=a/3;
	}
	else if(b<=c && b<=a){
		m=b/2;
	}
	else{
		m=c/2;
	}*/
	a -= (3*m);
	b -= (2*m);
	c -= (2*m);

	if(a>3)a=3;
	if(b>2)b=2;
	if(c>2)c=2;

	int ans = 0;

	for(int i=0;i<7;i++){
		res = 0;
		cal(a,b,c,i);
		ans=max(ans,res);
	}

	cout << (m*7)+ans << endl;
	return 0;
}
