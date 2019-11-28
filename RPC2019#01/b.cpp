#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(n<=2)cout << 1;
		else cout << n-2;
		cout << endl;
	}
	return 0;
}
