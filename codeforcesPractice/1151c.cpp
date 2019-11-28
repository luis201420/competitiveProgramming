#include <bits/stdc++.h>

#define MOD 1000000007 

using namespace std;

int main(){
	long long l,r;
	cin >> l >> r;
	int logL = floor(log2(l));
	int logR = floor(log2(r));
	cerr << logL << " " << logR << endl;
	long long a1,a2,a3,a4;
	
	a1=a2=a3=a4=0;
	
	if(logL%2==0){
		a1+=((l-1)-((1<<logL)-1))%MOD;
	}
	
	for(int i=0;i<=logL-1;i+=2){
		a1+=(1<<i)%MOD;
		a1%=MOD;
	}
	
	if(logL&1){
		a2+=((l-1)-((1<<logL)-1))%MOD;
	}
	
	for(int i=1;i<=logL-1;i+=2){
		a2+=(1<<i)%MOD;
		a2%=MOD;
	}
	
	if(logR%2==0){
		a3+=(r-((1<<logR)-1))%MOD;
	}
	for(int i=0;i<=logR-1;i+=2){
		a3+=(1<<i)%MOD;
		a3%=MOD;
	}
	if(logR&1){
		a4+=(r-((1<<logR)-1))%MOD;
	}
	for(int i=1;i<=logR-1;i+=2){
		a4+=(1<<i)%MOD;
		a4%=MOD;
	}
	
	a1%=MOD;a2%=MOD;a3%=MOD;a4%=MOD;
	
	r%=MOD;l%=MOD;
	
	long long p1 = (r-a3)%MOD;
	long long p2 = ((l-1)-a1)%MOD ;
	long long p3 = (r-a4)%MOD;
	long long p4 = ((l-1)-a2)%MOD ;	
	
	p3%=MOD;p4%=MOD;

	cout << p1*(p1+1)-(p2*(p2+1)) << " "<<((p3*p3)%MOD-(p4*p4)%MOD)%MOD<< endl;

	cout << (( (p1*(p1+1)%MOD)%MOD - (p2*(p2+1)%MOD)%MOD )%MOD + ( (p3*p3)%MOD - (p4*p4)%MOD )%MOD )%MOD << endl;

	return 0;
}
