#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,v,cont;
	cin >> n;
	cont = 0;
	for(int i=0;i<n;i++){
		cin >> v;
		cont+=(v<0);
	}
	cout << cont << endl;
	return 0;
}
