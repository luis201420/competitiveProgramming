#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n,res,s,k;
	cin >> t;
	vector<int> ns;
	for(int i=1;i<=t;i++){
		cin >> n >> k;
		ns.resize(n);
		for(int j=0;j<n;j++)cin >> ns[j];
		sort(ns.begin(),ns.end());
		res=1e9;
		for(int j=0;j<(n-k+1);j++){
			s=0;
			for(int h=0;h<k;h++)
				s+=ns[j+k-1]-ns[j+h];
			res=min(res,s);
		}
		cout << "Case #" << i << ": " << res << endl;
	}
	return 0;
}
