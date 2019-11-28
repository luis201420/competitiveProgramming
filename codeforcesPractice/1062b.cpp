#include <bits/stdc++.h>

using namespace std;

vector<bool> num;
vector<long long> primes;

void calcule(){
	num.assign(1000001,1);
	for(long long i=2;i<num.size();i++){
		if(num[i]){
			primes.push_back(i);
			for(long long j=i*i;j<num.size();j+=i)num[j]=0;
		}
	}
}

long long calNum(long long a){
	long long i=0,cont,res=1;
	while(a>1){
		cont =0;
		while(a%primes[i]==0){
			a/=primes[i];
			cont++;
		}
		if(cont&1)res*=primes[i];
		i++;
	}
	return res;
}

int main(){
	calcule();
	long long n;
	cin>>n;
	long long ant = n,res=0;
	n*=calNum(n);
	n=sqrt(n);
	res++;
	while(ant!=n){
		ant=n;
		n*=calNum(n);
		n=sqrt(n);
		res++;
	}
	cout << n << " " << res << endl;
	return 0;
}
