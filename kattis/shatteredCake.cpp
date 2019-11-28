#include<bits/stdc++.h>

using namespace std;

int main(){
	int w,n,a,b,res;
	cin >> w >> n;
	res=0;
	while(n--){
		cin >> a >> b;
		res+=(a*b);
	}
	cout << res/w << endl;
	return 0;
}
