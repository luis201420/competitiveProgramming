#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> w(n);
	for(int i=0;i<n;i++)cin >> w[i];
	vector<int> d(m);
	for(int i=0;i<m;i++)cin >> d[i];
	long long res = 0;
	vector<bool> visited;
	for(int i=0;i<m;i++){
		visited.assign(500,0);
		visited[d[i]-1]=1;
		for(int j=i-1;j>=0 && d[i]!=d[j];j--){
			if(visited[d[j]-1])continue;
			visited[d[j]-1]=1;
			res+=w[d[j]-1];
		}
	}
	cout << res << endl;
	return 0;
}
