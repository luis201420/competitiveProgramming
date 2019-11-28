#include <bits/stdc++.h>

using namespace std;

int sieve(const int &n,const int &k){
	int cont=0;
	vector<bool> used(n+1,1);
	for(long long i=2;i<=n;i++){
		if(used[i]){
			used[i]=0;
			cont++;
			if(cont==k){
				return i;
			}
			for(long long j=i*i;j<=n;j+=i){
				if(used[j]){
					used[j]=0;
					cont++;
				}
				if(cont==k){
					return j;
				}
			}
		}
	}
	return -1;
}

int main(){
	int n,k;
	cin >> n >> k;
	cout << sieve(n,k) << endl;
	return 0;
}
