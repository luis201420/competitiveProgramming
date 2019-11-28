#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<pair<int,int>> c;
	int n,a,b,k;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		c.push_back({a,b});
	}
	int res;
	cin >> k;
	for(int i=0;i<n;i++){
		if(c[i].first <= k && k<=c[i].second)res=i;
	}
	cout << (n-res) << endl;
	return 0;
}
