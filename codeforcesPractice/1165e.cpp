#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main(){
	int n;
	cin >> n;
	vector<long long> A(n),B(n);

	for(int i=0;i<n;i++){
		cin >> A[i];
		A[i] = (i+1)*1ll*(n-i)*A[i];
	}
	for(int i=0;i<n;i++){
		cin >> B[i];
	}
	
	sort(A.begin(),A.end());
	sort(B.begin(),B.end(),greater<long long>());
	long long s = 0;
	for(int i=0;i<n;i++){
		s= (s+(A[i]%MOD*1ll*B[i])%MOD)%MOD;
	}
	cout << s << endl;
	return 0;
}
