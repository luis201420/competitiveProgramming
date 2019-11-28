#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> ns(n);
	for(int i=0;i<n;i++)cin >> ns[i];
	sort(ns.begin(),ns.end());
	for(int i=0;i<n;i++){
		if(i!=0)cout << " ";
		cout << ns[i];
	}
	cout << "\n";
	return 0;
}
