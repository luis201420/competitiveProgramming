#include<bits/stdc++.h>

using namespace std;

int main (){
	long long res;
	int n;
	while(scanf("%d",&n)){
		if(n==0)break;
		res=1;
		for(int i=2;i<=n;i++){
			res+=(i*i);
		}
		printf("%d\n",res);
	}
	return 0;
}
