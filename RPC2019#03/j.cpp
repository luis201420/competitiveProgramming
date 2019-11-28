#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,s,v;
	cin >> n >> s;
	priority_queue<int> q;
	for(int i=0;i<n;i++){
		cin >> v;
		q.push(v);
	}
	int ans = ceil((double(q.top())*double(s))/1000.0);
	cout << ans << endl;
	return 0;
}
