#include <bits/stdc++.h>

using namespace std;

int ans;
vector<int> ns;

void bs(int a, int b){
	if(a==b)return ;
	bool v=1;
	for(int i=a;i<b;i++){
		if(ns[i+1]<ns[i]){
			v=0;
			break;
		}
	}
	if(v){ans=max(ans,b-a+1);}
	else{
		int m = (a+b)/2;
		bs(a,m);
		bs(m+1,b);
	}
}

int main(){
	int n;
	cin >> n;
	ns.resize(n);
	for(int i=0;i<n;i++) cin >> ns[i];
	ans=1;
	bs(0,n-1);
	cout << ans << endl;
	return 0;
}
