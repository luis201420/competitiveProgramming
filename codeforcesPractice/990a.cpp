#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n,m;
	int a,b;
	cin >> n >> m >> a >> b;

	cout << min((n%m)*b,(m-(n%m))*a) << endl;
	return 0;
}
