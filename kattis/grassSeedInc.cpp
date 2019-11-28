#include <bits/stdc++.h>

using namespace std;

int main(){
	double c,l,a,b;
	cin >> c >> l;
	double res=0;
	for(int i=0;i<l;i++){
		cin >> a >> b;
		res+=((a*b)*c);
	}
	cout << setprecision(7) << fixed;
	cout << res << endl;
	return 0;
}
