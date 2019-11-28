#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string s;
	cin >> n;
	vector<double> ns(n);
	for(int i=0;i<n;i++){
		cin >>s>> ns[i];
	}
	sort(ns.begin(),ns.end());
	double res=0;
	double aux=n;
	for(int i=0;i<n;i++){
		res+=(aux*ns[i]);
		aux--;
	}
	cout << setprecision(4) << fixed;
	cout << res << endl;
	return 0;
}
