#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a;
	vector<int> al;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		al.push_back(a);
	}
	sort(al.begin(),al.end());
	if(n==2) cout << 0;
	else cout << min(abs(al[1]-al[n-1]),abs(al[0]-al[n-2]));
	cout << endl;
	return 0;
}
