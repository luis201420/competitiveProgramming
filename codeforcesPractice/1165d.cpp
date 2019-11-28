#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n;
	vector<long long> d1,d2;
	cin >> t;
	bool ver;
	while(t--){
		cin >> n;
		d1.resize(n);
		for(int i=0;i<n;i++){
			cin >> d1[i];
		}
		sort(d1.begin(),d1.end());
		long long x = d1[0]*d1[d1.size()-1];
		//cerr << x << endl;
		for(long long i=2;i<=sqrt(x);i++){
			if(x%i==0){
				d2.push_back(i);
				if(i!=(x/i))
					d2.push_back(x/i);
			}
		}
		sort(d2.begin(),d2.end());
		ver=1;
		for(int i=0;i<min(d1.size(),d2.size());i++){
			//cerr << d1[i] << " " << d2[i] << endl;
			if(d1[i]!=d2[i]){
				ver=0;
				break;
			}
		}
		if(ver)cout << x << endl;
		else cout << -1 << endl;
		d2.clear();
	}
	return 0;
}
