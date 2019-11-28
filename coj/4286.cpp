#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,v;
	scanf("%d",&n);
	int minV=1e9,maxV=0;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		minV=min(minV,v);
		maxV=max(maxV,v);
		printf("%d\n",maxV + minV);
	}
	return 0;
}
