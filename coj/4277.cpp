#include <bits/stdc++.h>

using namespace std;

const int NN = 100000000;

vector<bool> primes;


void sieve(){
	vector<bool> used(NN,1);
	primes.assign(NN,0);
	for(long long i=2;i<NN;i++){
		if(used[i]){
			primes[i]=1;
			for(long long j=i*i;j<NN;j+=i)used[j]=0;
		}
	}
}

int main(){
	sieve();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k,aux;
	string n;
	bool v;
	while(cin >> k >> n){
		v=1;
		for(int i=0;i<n.size();i+=k){
			aux=atoi((n.substr(i,k)).c_str());
			if(!primes[aux])v=0;
		}
		if(v)printf(":)\n");
		else printf(":(\n");
	}
	return 0;
}
