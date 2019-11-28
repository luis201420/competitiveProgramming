#include <bits/stdc++.h>

using namespace std;

long long A,B;

inline bool f1(long long a,long long b, long long c){
	long long p1 =((2*b)+c);
	long long p2 =(2*(b+a));
	if(max(p1,p2)<=max(A,B) && min(p2,p1)<=min(A,B))return 1;
	else return 0;
}

inline bool f2(long long a, long long b, long long c){
	long long p1 =((3*a)+(b+c));
	long long p2 = (b+c);
	if(max(p1,p2)<=max(A,B) && min(p2,p1)<=min(A,B))return 1;
	else return 0;
}

int main(){
	long long n,x,y,z;
	bool r,t;
	scanf("%lld",&n);
	while(n--){
		scanf("%lld %lld %lld %lld %lld",&A,&B,&x,&y,&z);
		r=f1(x,y,z); t=f2(x,y,z);
		if(r || t){
			printf("POSSIBLE\n");
			continue;
		}
		r=f1(x,z,y); t=f2(x,z,y);
		if(r||t){
			printf("POSSIBLE\n");
			continue;
		}
		r=f1(y,x,z); t=f2(y,x,y);
		if(r||t){
			printf("POSSIBLE\n");
			continue;
		}
		r=f1(y,z,x); t=f2(y,z,x);
		if(r||t){
			printf("POSSIBLE\n");
			continue;
		}
		r=f1(z,x,y); t=f2(z,x,y);
		if(r||t){
			printf("POSSIBLE\n");
			continue;
		}
		r=f1(z,y,x); t=f2(z,y,x);
		if(r||t){
			printf("POSSIBLE\n");
			continue;
		}
		printf("IMPOSSIBLE\n");
	}
	return 0;
}
