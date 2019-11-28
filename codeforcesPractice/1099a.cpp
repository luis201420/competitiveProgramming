#include <bits/stdc++.h>

using namespace std;

int main(){
	int w,h,u1,d1,u2,d2;
	cin >> w >> h;
	cin >> u1 >> d1;
	cin >> u2 >> d2;

	while(h>=max(d1,d2)){
		w+=h;
		h--;
	}
	if(d1>d2){ w-=u1; d1=-1e9;}
	else {w-=u2; d2=-1e9;}
	if(w<0) w=0;
	while(h>=max(d1,d2)){
		w+=h;
		h--;
	}
	if(d1>d2) w-=u1;
	else w-=u2;
	if(w<0) w=0;
	while(h>0){
		w+=h;
		h--;
	}
	cout << w << endl;
	return 0;
}
