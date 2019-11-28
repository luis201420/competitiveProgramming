#include <bits/stdc++.h>

using namespace std;


void sieve(int limit,vector<int> & primes){
	
	vector<bool> used(limit+1,1);

	for(int p=2;(p*p)<limit;p++){
		if(used[p]){
			for(int j=p*2;j<limit;j+=p) used[j]=0;
		}
	}
	for(int p=2;p<limit;p++){
		if(used[p]) primes.push_back(p);
	}
}

void segmentSieve(int n,int m){
	vector<int> primes;
	int limit = floor(sqrt(m))+1;
	sieve(limit,primes);

	int low = n;
	int high = n+limit;
	
	for(int i=0;i<primes.size();i++){
		if(primes[i]>=n)cout << primes[i] << endl;
	}

	vector<bool> mark;
	//cerr << low << endl;
	while(low < m){
		//cerr << low <<endl;
		if(high >= m) high=m;
		
		mark.assign(limit+1,1);
		
		for(int i=0;i<primes.size();i++){
			int loLim = floor(low/primes[i])*primes[i];
			if(loLim < low) loLim += primes[i];

			for(int j=loLim;j<high;j+=primes[i])
				mark[j-low] = 0;
		}
		for(int i=low ; i<high;i++){
			if(mark[i-low]) cout << i << endl;
		}
		low += limit;
		high += limit;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t,n,m;
	//segmentSieve(1000000000);
	cin >> t;
	for(int i=0;i<t;i++){
		if(i!=0)cout << endl;
		cin >> n >> m;
		if(n==1)n++;
		segmentSieve(n,m+1);
	}
	return 0;
}
