#include <bits/stdc++.h>

using namespace std;

int main(){
	long long a,b,c;
	cin >> a >> b >> c;
	long long aux = min(a,b);
	long long ans = (2*aux)+(2*c);
	if((a-aux)>0 || b-aux > 0)ans++;
	cout << ans << endl;
	return 0;
}
