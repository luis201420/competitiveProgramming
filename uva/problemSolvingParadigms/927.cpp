#include <bits/stdc++.h>

using namespace std;

int main(){
	int cases,g,c,d,k,n,aux,acum;
	long long res;
	vector<int> coef;
	cin >> cases;
	while(cases --){
		cin >> g;
		g++;
		while(g--){
			cin >> c;
			coef.push_back(c);
		}
		cin >> d >> k;

		n=0;
		aux=2;
		acum=d;
		while(k>acum){
			acum+=aux*d;
			n++;
			aux++;
		}
		res = 0;
		n++;
		for(int i=0;i<coef.size();i++){
			res+=(coef[i]*pow(n,i));
		}

		cout << res << endl;
		coef.clear();
	}
	return 0;
}
