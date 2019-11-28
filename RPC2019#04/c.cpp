#include <bits/stdc++.h>

using namespace std;

vector<long long> fac;
vector<long long> primes;

void sieve(){
	vector<bool> used(1000001,1);
	for(long long i=2;i<=1000000;i++){
		if(used[i]){
			primes.push_back(i);
			for(long long j=i*i;j<=1000000;j+=i)used[j]=0;
		}
	}
}

void get_f(long long x){
	int p=0;
	while(x!=1 && p<primes.size()){
		while(x%primes[p]==0){
			//cerr << primes[p] << endl;
			x/=primes[p];
			fac.push_back(primes[p]);
		}
		p++;
	}
}

int main(){
	sieve();
	long long n;
	cin >> n;
	get_f(n);
	vector<long long> res1(3,1);
	long long fn = fac.size();
	long long aux1,aux2,aux3;
	long long m1,m2,m3;
//	for(long long i=fn-1;i>=0;i--){
	for(long long i=0;i<fn;i++){
		aux1=res1[0]*fac[i];
		aux2=res1[1]*fac[i];
		aux3=res1[2]*fac[i];
		m1 =abs(aux1-res1[1])+abs(aux1-res1[2])+abs(res1[1]-res1[2]);
		m2 =abs(aux2-res1[0])+abs(aux2-res1[2])+abs(res1[0]-res1[2]);
		m3 =abs(aux3-res1[0])+abs(aux3-res1[1])+abs(res1[0]-res1[1]);
		if(m1 <= m2 && m1 <= m3){
			res1[0]*=fac[i];
		}
		else if(m2 <= m1 && m2 <= m3){
			res1[1]*=fac[i];
		}
		else if(m3 <= m2 && m3 <= m1){
			res1[2]*=fac[i];
		}
		cerr << res1[0] << " " << res1[1] << " " << res1[2] << endl;
	}		
	long long ans1=2*(res1[0]*res1[1]+res1[0]*res1[2]+res1[1]*res1[2]);
	cout << ans1 << endl;
	return 0;
}
