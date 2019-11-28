#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	long long v,res;
	vector<long long> a,b,c;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> v;
		a.push_back(v);
		c.push_back(v);
	}
	for(int i=0;i<m;i++){
		cin >> v;
		b.push_back(v);
		c.push_back(v);
	}
	
	sort(c.begin(),c.end());
	v=c[m-1];

	res=0;
	for(int i=0;i<n;i++){
		if((v-a[i])>0)res+=(v-a[i]);
	}
	for(int i=0;i<m;i++){
		if((b[i]-v)>0)res+=(b[i]-v);
	}

	cout << res << endl;
	return 0;
}
