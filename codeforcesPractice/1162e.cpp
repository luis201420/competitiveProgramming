#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int minN = 1e9;
	vector<int> ns(n);
	for(int i=0;i<n;i++){
		cin >> ns[i];
		minN=min(minN,ns[i]);
	}
	int cont = 0;
	for(int i=0;i<n;i++){
		cont+=(ns[i]==minN);
	}
	if(cont>(n/2)) cout << "Bob" << endl;
	else cout << "Alice" << endl;
	return 0;
}
