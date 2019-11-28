#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n,k,v,res;
	vector<int> h;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i=0;i<n;i++){
			cin >> v;
			h.push_back(v);
		}
		if(k==1){
			cout << 0 << endl;
			h.clear();
			continue;
		}
		sort(h.begin(),h.end());
		res = 1e9+1;
		for(int i=0;i<n-k+1;i++){
			res=min(res,h[i+(k-1)]-h[i]);
		}
		cout << res << endl;
		h.clear();
	}
	return 0;
}
