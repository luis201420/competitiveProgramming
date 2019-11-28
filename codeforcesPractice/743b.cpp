#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n,k;
	cin >> n >> k;
	if(k&1){
		cout << 1 << "\n";
		return 0;
	}
	k--;
	ll i = 1;
	ll a = 4, b = 1;
	ll aux = pow(2,b)-1;
	while((k-aux)%a!=0){
		a*=2;
		b++;
		aux=pow(2,b)-1;
		i++;
	}
	cout << i+1 << "\n";
	return 0;
}
