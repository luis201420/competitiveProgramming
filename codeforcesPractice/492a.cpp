#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n,s;
	cin >> n;
	ll i=1;
	s=(i*(i+1))/2;
	while(s<n){
		i++;
		s+=((i*(i+1))/2);
		//cerr <<i<<" "<< s << "\n";
	}
	if(s!=n)i--;
	cout << i << endl;
	return 0;
}
