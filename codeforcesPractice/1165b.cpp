#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> ns(n);
	for(int i=0;i<n;i++){
		cin >> ns[i];
	}
	sort(ns.begin(),ns.end());
	int ans = 0,cur=1;
	for(int i=0;i<n;i++){
		if(cur <= ns[i]){
			ans++;
			cur++;
		}
	}
	cout << ans << endl;
	return 0;
}
