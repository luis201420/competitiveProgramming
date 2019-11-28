#include <bits/stdc++.h>

using namespace std;

bool ver(string &s1,string &s2){
	int t1=s1.size(),t2=s2.size();
	if(t1<t2) return 1;
	if(t1>t2) return 0;
	for(int i=0;i<t1;i++){
		if(s1[i]>s2[i]) return 0;
	}
	if(s1[t1-1]>=s2[t1-1])return 0;
	return 1;
}

int main(){
	long long q,n,s;
	string x,n1,n2;
	cin >> q;
	bool v;
	while(q--){
		cin >> n >> x;
		v=1;
		for(int k=1;k<n;k++){
			n1=x.substr(0,k); n2=x.substr(k,n-k);
			if(ver(n1,n2)){
				cout << "YES\n"; v=0;
				cout << 2 << endl;
				cout << n1 << " " << n2 << endl;
				break;
			}
		}
		if(v) cout << "NO" << endl;
	}
	return 0;
}
