#include<bits/stdc++.h>

using namespace std;

int main(){
	double c,s,aux;
	double l,a,b;
	cin >> c;
	cin >> l;
	s = 0;
	while(l--){
		cin >> a >> b;
		aux = (a*b);
		s += (aux*c);
	}
	cout << setprecision(7) << fixed;
	cout << s << endl;
	return 0;
}
