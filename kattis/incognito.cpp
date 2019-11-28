#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n;
	cin >> t;
	string p,c;
	map<string,int> cont;
	int res;
	while(t--){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> p >> c;
			cont[c]++;
		}
		res=1;
		for(auto it:cont){
			res*=(it.second+1);
		}
		cout << res-1 << endl;
		cont.clear();
		//cant.clear();
	}
	return 0;
}
