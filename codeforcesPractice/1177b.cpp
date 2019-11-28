#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	cin >> n;
	long long acum1=0,acum2=0,i;
	for(i=0;;i++){
		if(acum2>n)break;
		acum1+=9*pow(10,i);
		acum2+=(i+1)*9*pow(10,i);
	}
	acum2-=(i)*9*pow(10,i-1);
	acum1-=9*pow(10,i-1);
	//cerr << acum1 << " " << acum2 << endl;
	long long a = n-acum2;
	long long b = a%i;
	a/=i;
	a = acum1 + a;
	string s;
	//cerr << a << " " << b << endl;
	if(b == 0){
		s=to_string(a);
		cout << s[s.size()-1] << endl;
	}
	else{
		s=to_string(a+1);
		cout << s[b-1] << endl;
	}
	return 0;
}
