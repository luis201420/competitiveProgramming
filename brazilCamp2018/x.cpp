#include <bits/stdc++.h>

using namespace std;

int main(){
	set<int> res;
	int n,v;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> v;
		if(n&1)res.insert(v);
		else res.insert(-v);
	}
	for(auto u:res){
		if(n&1)cout << u << endl;
		else cout << -u << endl;
	}
	return 0;
}
