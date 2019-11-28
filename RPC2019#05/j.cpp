#include <bits/stdc++.h>

using namespace std;

int main(){
	long long m;
	cin >> m;
	long long n=m+1;
	long long aux;
	while(1){
		aux = (double(n*(n+1))/2.0)+(double(m*(m-1))/2.0);
		if((long long)(sqrt(aux))*(long long)(sqrt(aux))==aux)break;
		n++;
	}
	cout << m <<" " <<int(sqrt(aux)) << " " << n << endl;
	return 0;
}
