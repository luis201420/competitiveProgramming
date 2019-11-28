#include <bits/stdc++.h>

#define L(i) (i<<1)+1
#define R(i) (i+1)<<1

using namespace std;

vector<int> A;

vector<int> tree;

int gcd (int a, int b) {
	while (b) {
		a %= b;
        	swap(a, b);
   	}
    	return a;
}

void create(int i,int a,int b){
	if(a==b){
		tree[i]=A[a];
		return;
	}
	int m=(a+b)/2;
	create(L(i),a,m);
	create(R(i),m+1,b);
	tree[i]=gcd(tree[L(i)],tree[R(i)]);
}

int rmq(int i,int a,int b,int qa,int qb){
	if(qb < a || b < qa)return 0;
	if(qa <= a && b<=qb){
		return tree[i];
	}
	int m=(a+b)/2;
	int gL = rmq(L(i),a,m,qa,qb);
	int gR = rmq(R(i),m+1,b,qa,qb);
	return gcd(gL,gR);
}

void update(int i,int a,int b,int p,int v){
	if(p<a || b<p)return;

	if(p==a && b==p){
		tree[i]=v;
		return;
	}
	int m=(a+b)/2;
	update(L(i),a,m,p,v);
	update(R(i),m+1,b,p,v);
	tree[i]=gcd(tree[L(i)],tree[R(i)]);
}

int main(){
	int n;
	cin >> n;
	A.resize(n);
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	
	tree.assign(4*n,0);
	create(0,0,n-1);

	int ans=0;

	for(int i=0;i<n;i++){
		update(0,0,n-1,i,0);
		ans=max(ans,rmq(0,0,n-1,0,n-1));
		//cerr << rmq(0,0,n-1,0,n-1) << endl;
		update(0,0,n-1,i,A[i]);
	}
	cout << ans << endl;
	return 0;
}
