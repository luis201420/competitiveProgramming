#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,k,aux;
	long long r,ans;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %d",&r,&k);
		aux = k/2.0;
		if(k%2==0){
			r=2*r;
			aux--;
		}
		ans=1;
		if(aux&1){ans=2;aux--;}
		else ans=1;
		r=r*pow(2,aux/2);
		r*=r;
		ans*=r;
		printf("%lld",ans);
		if(k&1)printf("PI\n");
		else printf("\n");
	}
	return 0;
}
