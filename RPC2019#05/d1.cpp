#include<bits/stdc++.h>

using namespace std;

vector<long long> tree,A;
int n,m;

void add(int k,long long x){
	while(k<=n){
		tree[k]+=x;
		k+=(k&-k);
	}
}

long long sum(int k){
	long long s=0;
	while(k>=1){
		s+=tree[k];
		k-=(k&-k);
	}
	return s;
}

//*********
long long verificate(int x,bool v){
	long long sL = sum(x-1);
	long long sR = sum(n)-sum(x);
	long long ac = (2*(sL))+A[x-1]-sum(n);
	if(v)ac=abs(ac);
	if(A[x-1]&1/* && sL!=sR*/) ac--;
	return ac;
}

//********
int binarySearch( ){
	int x=1, y=n, k,r=n;
		while(x<=y){
		k=(x+y)/2;
		if(verificate(k,0)>=0) {y=k-1;r=k;}
		else x=k+1;
	}
	return r;
}

int main(){
	
	cin >> n >> m;
	
	A.resize(n);
	tree.assign(n+1,0);
	
	for(int i=0;i<n;i++){
		cin >> A[i];
		add(i+1,A[i]);
	}
	
	long long pos,v,obj,ans;
	long long v1,v2,v3;

	while(m--){
		cin >> pos >> v;
		add(pos+1,v-A[pos]);
		A[pos]=v;
		ans = binarySearch( );
		if(ans>0 && ans <=n){v1 = verificate(ans,1);}
		else {v1=1e9;}
		if((ans-1)>0){v2 = verificate(ans-1,1);}
		else{v2=1e9;}
		if((ans-2)>0){v3 = verificate(ans-2,1);}
		else{v3=1e9;}
		v1=abs(v1);v2=abs(v2);v3=abs(v3);
		if(v3 <= v1 && v3 <= v2) cout << ans-3 << endl;
		else if(v2<=v1 && v2<=v3) cout << ans-2 << endl;
		else cout << ans-1 << endl;
	}
	return 0;
}
