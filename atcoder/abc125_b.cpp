#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> ns(n);
	for(int i=0;i<n;i++){
		cin >> ns[i];
	}
	int v;
	priority_queue<int> q;
	for(int i=0;i<n;i++){
		cin >> v;
		q.push(ns[i]-v);
	}
	int ans = 0;
	while(!q.empty()){
		v=q.top();
		q.pop();
		if(v<=0) break;
		ans+=v;
	}
	cout << ans << endl;
	return 0;
}
