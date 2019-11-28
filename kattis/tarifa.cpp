#include <bits/stdc++.h>

using namespace std;

int main(){
	int x,n,v,res;
	cin >> x;
	cin >> n;
	res=0;
	while(n--){
		res+=x;
		cin >> v;
		res-=v;
	}
	cout << res+x << endl;
	return 0;
}
