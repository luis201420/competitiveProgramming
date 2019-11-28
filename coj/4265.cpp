#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll t,a,b,ans;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&a,&b);
		ans=floor(a/log2(10) + (b*log2(5))/(log2(10)));
		printf("%lld\n",ans+1);
	}
	return 0;
}
