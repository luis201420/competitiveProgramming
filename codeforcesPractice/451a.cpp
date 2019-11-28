#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int r = min(n,m);
	if(r&1)cout << "Akshat";
	else cout << "Malvika";
	cout << "\n";
	return 0;
}
