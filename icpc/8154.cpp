#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n,v;
	long long x0,x1,x2,y0,y1,y2;
	long long a0,a1,a2;
	while(cin >> n){
		x0=x1=x2=0;
		for(int i=0;i<n;i++){
			cin >> v;
			if(i%3==0)x2+=v;
			else if(i%3==1)x0+=v;
			else x1+=v;
		}
		y0=y1=y2=0;
		for(int i=0;i<n;i++){
			cin >> v;
			if(i%3==0)y2+=v;
			else if(i%3==1)y0+=v;
			else y1+=v;
		}
		a0 = (x0*y2)+(x2*y0)+(x1*y1);
		a1 = (x1*y2)+(x0*y0)+(x2*y1);
		a2 = (x2*y2)+(x1*y0)+(x0*y1);
		cout << a0 << " " << a1 << " " << a2 << endl;
	}
	return 0;
}
