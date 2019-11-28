#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,s=0,g=0,v;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> v;
		if(g<v) g=v;
		s+=v;
	}
	int k = ((2*s)/n)+1;
	if(k<g) k = g;
	cout << k << endl;
	return 0;
}
