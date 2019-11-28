#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n,res;
	cin >> n;
	res = (n*(n+1))/2;
	if(res&1)cout << 1 << endl;
	else cout << 0 << endl;
}
