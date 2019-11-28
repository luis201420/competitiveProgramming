#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> ns(n);
	for(int i=0;i<n;i++)cin >> ns[i];
	int res=0,aux;
	for(int i=0;i<n-1;i++){
		aux=(ns[i+1]-ns[i-1]);
		res+=min(ns[i],aux);
	}	
	res+=ns[n-1];
	cout << res << endl;
	return 0;
}
