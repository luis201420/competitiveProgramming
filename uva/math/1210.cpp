#include <bits/stdc++.h>

using namespace std;

vector<long long> primes;

void generator(){
	primes.push_back(2);
	vector<bool> ver(10050,1);
	for(long long i=3;i<ver.size();i+=2){
		if(ver[i]){
			primes.push_back(i);
			for(long long j=i*i;j<ver.size();j+=(2*i))ver[j]=0;
		}
	}
}

int main(){
	generator();
	long long n,i,j,acum,cont;
	while(cin >> n){
		if(n==0)break;
		i=j=0;
		acum=0;
		cont=0;
		while(primes[i]<=n){
			while (i<primes.size() && acum>n){
				acum-=primes[i];
				i++;
			}
			if(acum==n){
				cont++;
				acum-=primes[i];
				i++;
			}
			while (j<primes.size() && acum<n){
				acum+=primes[j];
				j++;
			}
			if(acum==n){
				cont++;
				acum-=primes[i];
				i++;
			}
		}
		cout << cont << endl;
	}
	return 0;
}
