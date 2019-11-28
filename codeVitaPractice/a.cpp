#include <bits/stdc++.h>

using namespace std;

int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}

int main(){
	int n;
	cin >> n;
	int prime[6]={2,3,5,7,11,13};
	bool used[6]={0,0,0,0,0,0};
	int cont =0;
	for(int i=0;i<6;i++){
		if(gcd(n,prime[i])!=1){
			used[i]=1;
		}
	}
	for(int i=0;i<6;i++){
		if(used[i]){
			cont+=(n/prime[i]);
			int pre=(n/prime[i]);
			//cerr << cont << endl;
			int j=i-1;
			while(j>=0){
				if(used[j]){
					cont-=(pre/prime[j]);
					pre-=(pre/prime[j]);
				}
				j--;
			}
		}
	}
	cout << n - cont;
	return 0;
}
