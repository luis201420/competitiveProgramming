#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> p;
	int n,m,v;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> v;
		p.push_back(v);
	}
	sort(p.begin(),p.end());
	int res=1e9;
	for(int i=0;i<(m-n+1);i++){
		if((p[i+n-1]-p[i])<res)res=p[i+n-1]-p[i];
	}
	cout << res << endl;
	return 0;
}
