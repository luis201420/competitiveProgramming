#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	while (b) {
		a %= b;
        	swap(a, b);
    	}
    	return a;
}

int lcm(int a, int b){
	return a/gcd(a,b)*b;
}

int main(){
	int t,m,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&m,&n);
		printf("%d\n",lcm(m,n));
	}
	return 0;
}
