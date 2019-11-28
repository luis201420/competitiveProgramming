#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int a,b,c, x,y,z;
	cin >> n;
	x=y=z=0;
	while(n--){
		cin >> a >> b >> c;
		x+=a;y+=b;z+=c;
	}
	if(x==0 && y==0 && z==0)cout << "YES";
	else cout << "NO";
	cout << endl;

	return 0;
}
