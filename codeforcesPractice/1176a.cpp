#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	long long cont2,cont3, cont5;
	long long x;
	cin >> t;
	while(t--){
		cin >> x;
		cont2=cont3=cont5=0;
		while(x%2==0){
			x/=2;
			cont2++;
		}
		while(x%3==0){
			x/=3;
			cont3++;
		}
		while(x%5==0){
			x/=5;
			cont5++;
		}
		if(x!=1){
			cout << -1 << endl;
		}
		else{
			cout << cont2+(2*cont3)+(3*cont5) << endl;
		}
	}
	return 0;
}
