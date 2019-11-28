#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	int n,m,v;
	vector<bool> ns;
	scanf("%d",&t);
	bool ver;
	while(t--){
		scanf("%d %d",&n,&m);
		ns.assign(n,0);
		while(m--){
			scanf("%d",&v);
			ns[v-1]=1;
		}
		ver=0;
		for(int i=0;i<n;i++){
			if(!ns[i]){
				if(ver)printf(" ");
				printf("%d",i+1);
				ver=1;
			}
		}
		printf("\n");
	}
	return 0;
}
