#include <bits/stdc++.h>

using namespace std;

bool ver(long long x){
	int cont=0;
	for(int i=2;i<=ceil(sqrt(x));i++){
		if(x%i==0)cont++;
	}
	return (cont==1);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long n,v;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> v;
		if(ver(v))cout << "YES"<< endl;
		else cout << "NO" << endl;
	}
	return 0;
}
