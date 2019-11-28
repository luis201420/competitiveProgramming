#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int a,b,c;
	cin >> n;

	if((n-2)%3!=0){
		a=1;
		b=1;
		c=n-2;
	}
	else{
		a=1;
		b=2;
		c=n-3;
	}
	cout << a << " " << b << " " << c << endl;
	
	return 0;
}
