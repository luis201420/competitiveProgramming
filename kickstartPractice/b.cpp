#include<bits/stdc++.h>

using namespace std;

long long calSum(string a){
	long long r=0;
	for(int i=0;i<a.size();i++){
		r+=(a[i]-'0');
	}
	return r;
}

int main(){
	int t,n,m;
	string s;
	long long v,res;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n;
		cin >> s;
		res=0;
		m = ceil(float(n)/2.0);
		for(int j=0;j<=(n/2);j++){
			res=max(res,calSum(s.substr(j,(m))));
		}
		cout << "Case #"<<i<<": " << res << endl;
	}
	return 0;
}
