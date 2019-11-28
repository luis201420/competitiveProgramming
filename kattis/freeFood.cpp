#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b;
	cin >> n;
	set<int> res;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		for(;a<=b;a++)res.insert(a);
	}
	cout << res.size() << endl;
	return 0;
}
