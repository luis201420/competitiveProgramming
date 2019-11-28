#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c,x,y,z;
	cin >> a >> b >> c;
	
	x = sqrt((a*c)/b);
	y = (b*x)/c;
	z = c/x;

	cout << (4*x)+(4*y)+(4*z) << endl;
	return 0;
}
