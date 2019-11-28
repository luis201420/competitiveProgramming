#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n,s,aux,m;
	vector<long long> all,sums;
	while(cin >> n){
		for(long long i=0;i<(1<<n);i++){
			cin >> s;
			all.push_back(s);
		}
		m = 0;
		for(long long i=0;i<all.size();i++){
			aux=0;
			for(long long j=1;j<(1<<n);(j=j<<1)){
				aux+=all[i^j];
			}
			sums.push_back(aux);
		}
		for(long long i=0;i<all.size();i++){
			for(long long j=1;j<(1<<n);(j=j<<1)){
   	                     if((sums[i]+sums[i^j])>m) m = sums[i]+sums[i^j];
       		        }
		}
		cout << m << endl;
		all.clear();
		sums.clear();
	}
	return 0;
}
