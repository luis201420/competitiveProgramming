#include<bits/stdc++.h>

using namespace std;

string r;
int n;

int ver(long long a){
	r="";
	while(a>=2){
		r+=to_string(a%2);
		a/=2;
	}
	r+=to_string(a);
	if(r.size()<n)r+=string(n-r.size(),'0');
	for(int i=1;i<n;i++){
		if(r[i]=='1' && r[i]==r[i-1])return i-1;
	}
	return -1;
}

int main(){
	long long ans=0;
	int k,q;
	cin >> n >> k;
	while(k>0){
		q=ver(ans);
		if(q==-1){k--;ans++;}
		else{
			q=n-q;
			ans|=((long long)(1<<44)-1)<<q;
		}
	}
	reverse(r.begin(),r.end());
	cout << r << endl;
	cerr << ans << endl;
	return 0;
}
