#include <bits/stdc++.h>

#define PI 3.14159265

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<double> l(4);
	double s = 0;
	double m = 1;
	for(int i=0;i<4;i++){
		cin >> l[i];
		s+=l[i];
		m*=l[i];
	}

	s/=2.0;
	double angle = 90.0 * PI / 180.0;

	double ans = sqrt(((s-l[0])*(s-l[1])*(s-l[2])*(s-l[3]))-(m*cos(angle)*cos(angle)));
	cout << setprecision(10) << fixed;
	cout << ans << endl;
	return 0;
}
