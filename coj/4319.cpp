#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		if(n<=2)printf("%d\n",n);
		else if(n==3)printf("4\n");
		else printf("%d\n",(3*n)-5);
	}
	return 0;
}
