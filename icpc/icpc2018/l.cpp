#include <bits/stdc++.h>

using namespace std;

#define N 100001

typedef long long ll;

vector<int> primes;
vector<pair<int,int>> qs;

void sieve(){
	vector<bool> isPrime(N,1);
	primes.push_back(2);
	for(ll i=3;i<N;i+=2){
		if(isPrime[i]){
			primes.push_back(i);
			for(ll j=i*i;j<N;j+=(i<<1))isPrime[j]=0;
		}
	}
}

/********** BIT *************/
vector<int> bit;

int sum(int k){
	int s=0;
	while(k>=1){
		s+=bit[k];
		k-=(k&-k);
	}
	return s;
}

void add(int k,int x){
	while(k<=N){
		bit[k]+=x;
		k+=(k&-k);
	}
}

bool myComp(const int &a,const int &b){
	return qs[a].second > qs[b].second;
}

int main(){
	vector<int> qi,res;
	sieve();
	int q,n,k;
	cin >> q;
	for(int i=0;i<q;i++){
		cin >> n >> k;
		qs.push_back({n,k});
		qi.push_back(i);
	}
	sort(qi.begin(),qi.end(),myComp);
	
	bit.resize(N+1);
	for(int i=1;i<=N;i++){
		add(i,1);
	}

	vector<bool> ver(N,0);
	res.resize(q);
	for(int i=0;i<q;i++){
		n = qs[qi[i]].first;
		k = qs[qi[i]].second;
		k = upper_bound(primes.begin(),primes.end(),k)-primes.begin();
		for(int j=k;j<primes.size();j++){
			if(ver[primes[j]])break;
			int aux=primes[j];
			while(aux<N){
				if(!ver[aux]){
					add(aux,-1);
					ver[aux]=1;
				}
				aux+=primes[j];
			}
		}
		res[qi[i]] = sum(n)-sum(2)+1;
	}
	
	for(int i=0;i<res.size();i++){
		cout << res[i] << endl;
	}

	return 0;
}
