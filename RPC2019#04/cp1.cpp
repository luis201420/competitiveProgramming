#include <bits/stdc++.h>

using namespace std;



int main(){
	int a,b,c;
	int n,m;
	int ans=1e9;
	cin >> n;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			m = n/i;
			int j;
			for(j=sqrt(m);j>=1;j--){
				if(m%j==0)break;
			}
			a=i;
			b=j;
			c=m/j;
			ans=min(ans,2*(a*b+a*c+b*c));
		}
	}
	cout << ans << endl;
	return 0;
}
