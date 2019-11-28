#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n,v;
	vector<int> a,b;
	cin >> t;
	while(t--){
		cin >> n;
		b.assign(n,0);
		while(n--){
			cin >> v;
			a.push_back(v);
		}
		for(int i=0;i<a.size();i++){
			for(int j=i+1;j<b.size();j++){
				if(a[j]>=a[i])b[j]++;
			}
		}
		int res = 0;
		for(int i=1;i<b.size();i++)res+=b[i];
		cout << res<<endl;
		a.clear();
	}
	return 0;
}
