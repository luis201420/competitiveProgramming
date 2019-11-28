#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n,k,res,aux;
	cin >> n >> k;
	res = (n*k)+1;
	for(long long i=2;i<k;i++){
		if(n%i==0){
			aux=((n*k)/i)+i;
			res=min(res,aux);
		}
	}
	cout << res << endl;
	return 0;
}
