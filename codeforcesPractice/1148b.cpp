#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n,m,ta,tb,k;
	cin >> n >> m >> ta >> tb >> k;
	vector<ll> A(n),B(m),Bc(m);
	vector<bool> Au(n,0);

	int pos;
	int i;
	vector<ll>::iterator it;
	
	for(int i=0;i<n;i++){
		cin >> A[i];
		A[i]+=ta;
	}
	for(int j=0;j<m;j++){
		cin >> B[j];
		Bc[j]=upper_bound(A.begin(),A.end(),B[j])-A.begin();
	}

	for(i=0;i<n && k;i++){
		it = lower_bound(B.begin(),B.end(),A[i]);
		
		if(it == B.end()) break;
		
		pos = it-B.begin();

		if((m-pos) >= Bc[pos])Au[i]=1;
		else B.erase(it);
		
		k--;
	}
	
	if(it==B.end() || i>=n)
		cout << -1 << endl;
	else{
		for(i = 0 ; i<n ;i++){
			if(Au[i])continue;
			it = lower_bound(B.begin(),B.end(),A[i]);
			if(it==B.end())break;
			else{
				pos=it-B.begin();
				cout << B[pos]+tb << endl;
				break;
			}
		}
		if(it == B.end() || i>=n){
			cout << -1 << endl;
		}
	}
	return 0;
}
