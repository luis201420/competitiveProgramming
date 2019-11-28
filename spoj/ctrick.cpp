#include <bits/stdc++.h>

using namespace std;

int t,n;
vector<int> bit,sol;

void update(int pos, int v){
	for(;pos<=n;pos+=(pos&-pos)){
		bit[pos]+=v;
	}
}

int query(int k){
	int res=0;
	for(;k>0;k-=(k&-k)){
		res+=bit[k];
	}
	return res;
}

int queryAB(int a,int b){
	return query(b)-query(a-1);
}

int bs(int a,int b,int v){
	if(v==0) return a;
	int q;
	while(a<=b && b<=n){
		q=queryAB(a,b);
		if(q==v) return b;
		
		if(q>v)b=(a+b)/2;
		else b=(b+n)/2;
	}
	return -1;
}

void solution(){
	int x=1,dif=2,z=n,y,q;
	while(z>0){
		q=queryAB(x,n);
		if(q>=(dif%z))
			y=bs(x,n,dif%z);
		else{
			x=1;
			y=bs(x,n,(dif%z)-q);
		}

		cerr << x << " " << y << " " << dif << endl;
		
		update(y-1,-1);
		sol[y-1]=dif-1;

		x=y+1;
		z--;
		dif++;
	}
	cerr<<"FIN"<< endl;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		bit.assign(n+1,0);
		sol.assign(n,0);
		for(int i=1;i<=n;i++){
			update(i,1);
		}
		solution();
		for(int i=0;i<sol.size();i++){
			if(i!=0)cout << " ";
			cout << sol[i];
		}
		cout << endl;
	}	
	return 0;
}
