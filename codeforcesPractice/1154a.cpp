#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> ns(4);
	for(int i=0;i<4;i++){
		cin >> ns[i];
	}
	sort(ns.begin(),ns.end());
	int z = ns[3]-ns[0];
	int x = ns[2]-z;
	int y = ns[1]-z;
	cout << x << " " << y << " " << z << endl;
	return 0;
}
