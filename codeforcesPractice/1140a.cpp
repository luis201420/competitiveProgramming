#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> ns(n);
	for(int i=0;i<n;i++){
		cin >> ns[i];
	}
	int cont=0;
	int i=0,m;
	while(i<n){
		cont++;
		m=ns[i];
		while(i<n && i<m){
			m=max(m,ns[i]);
			i++;
		}
	}
	cout << cont << endl;
	return 0;
}
