#include <bits/stdc++.h>

#define M 998244353 

using namespace std;

long long binpow(long long a, long long b) {
    a %= M;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

int main(){
	int n,m;
	string sn,sm;
	cin >> n >> m;
	cin >> sn >> sm;
	reverse(sn.begin(),sn.end());
	reverse(sm.begin(),sm.end());

	int ones=0;
	for(int i=0;i<m;i++){
		ones+=(sm[i]=='1');
	}

	long long ans=0;
	for(int i=0;i<min(n,m);i++){
		if(sn[i]=='1')ans=(ans+((binpow(2,i))*ones))%M;
		if(sm[i]=='1')ones--;
	}
	cout << ans << endl;
	return 0;
}
