#include <bits/stdc++.h>

using namespace std;

const int N =1000000;

vector<int> primes;
vector<bool> primes_V;

void sieve(){
	vector<bool> used(N+1,1);
	primes_V.assign(N+1,0);
	for(long long i=2;i<=N;i++){
		if(used[i]){
			primes_V[i]=1;
			primes.push_back(i);
			used[i]=0;
			for(long long j=i*i;j<=N;j+=i)used[j]=0;
		}
	}
}

int main(){
	sieve();
	int x,p,r,cont;
	cin >> x;
	cont = 0;
	while(x>=4){
		p=lower_bound(primes.begin(),primes.end(),x)-primes.begin();
		p--;
		r=x-primes[p];
		while(!primes_V[r]){
			p--;
			r=x-primes[p];
		}
		x=primes[p]-(x-primes[p]);
		cont++;
	}
	cout << cont << endl;
	return 0;
}
