#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	map<int,int> cont;
	vector<int> ns(n);
	for(int i=0;i<n;i++){
		cin >> ns[i];
		cont[ns[i]]++;
	}
	sort(ns.begin(),ns.end());
	long long ans = 0;
	for(int i=0;i<n;i++){
		if(cont[ns[i]]>1){
			int j=ns[i]+1;
			while(cont[j]){
				j++;
			}
			ans+=(j-ns[i]);
			cont[j]++;
			cont[ns[i]]--;
		}
	}
	cout << ans << endl;
	return 0;
}
