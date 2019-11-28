#include <bits/stdc++.h>

using namespace std;

int main(){
	double n,l;
	cin >> n >> l;
	vector<double> ls(n);
	for(int i=0;i<n;i++){
		cin >> ls[i];
	}
	sort(ls.begin(),ls.end());
	double maxDist = 0;
	for(int i=0;i<n-1;i++){
		maxDist=max(maxDist,(ls[i+1]-ls[i]));
	}
	maxDist = max(maxDist/2,max(ls[0]-0,l-ls[n-1]));
	cout << setprecision(10)<<fixed;
	cout << maxDist << endl;
	return 0;
}
