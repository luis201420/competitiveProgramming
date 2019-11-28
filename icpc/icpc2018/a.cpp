#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
	if(b==0)return a;
	else return gcd(b,a%b);
	
}

int main(){
	int n,p1,p2;
	scanf("%d.%d",&p1,&p2);
	n = (p1*100)+p2;
	printf("%d\n",36000/gcd(36000,n));
	return 0;
}
