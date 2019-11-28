#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,a,b,n,sol,cont;
	char s[12];
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&a,&b);
		scanf("%d",&n);
		sol=(a+b+1)/2;
		printf("%d\n",sol);
		cont=0;
		fflush(stdout);
		while(scanf("%s",&s)){
			if(strcmp(s,"WRONG_ANSWER")==0)break;
			if(strcmp(s,"CORRECT")==0)break;
			if(strcmp(s,"TOO_SMALL")==0)a=sol+1;
			if(strcmp(s,"TOO_BIG")==0)b=sol-1;
			sol=(a+b+1)/2;
			printf("%d\n",sol);
			cont++;
			if(n==cont)break;
			fflush(stdout);
		}
		if(n==cont && strcmp(s,"CORRECT"))break;
		if(strcmp(s,"WRONG_ANSWER")==0)break;
		fflush(stdout);
	}
	return 0;
}
