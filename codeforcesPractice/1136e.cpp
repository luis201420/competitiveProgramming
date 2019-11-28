#include <bits/stdc++.h>

#define L(i) (i<<1)+1
#define R(i) (i+1)<<1

using namespace std;

vector<long long> L,dif;

vector<long long> lazy;
vector<long long> tree;
vector<bool> h;

void create_tree(int i, int a, int b){
	if(a==b){
		tree[i]=L[a];
		h[i]=1;
		return;
	}
	int m = (a+b)/2;
	create_tree(L(i),a,m);
	create_tree(R(i),m+1,b);
	tree[i]=tree[L(i)]+tree[R(i)];
}

int rmq(int i,int a,int b,int qa,int qb){
	if(qb<a || b<qa)return 0;

	if(qa<=a &&b <=qb){
		return tree[i];
	}

	if(lazy[i]){
		if(a!=b){
			tree[L(i)]+=lazy[i];
			if(!h[L(i)])tree[L(i)]+=lazy[i];
			lazy[L(i)]+=lazy[i];

			tree[R(i)]+=lazy[i];
			if(!h[R(i)])tree[R(i)]+=lazy[i];
			lazy[R(i)]+=lazy[i];
		}
		lazy[i]=0;
	}
	int m=(a+b)/2;
	long long r1 = rmq(L(i),a,m,qa,qb);
	long long r2 = rmq(R(i),m+1,b,qa,qb);

	return r1+r2;
}

void update_lazy(int i,int a,int b,int ua,int ub,int v){
	
	if(ub<a || b<ua)return;

	if(ua<=a && b<=ub){
		tree[i]+=v;
		if(!h[i])tree[i]+=v;
		lazy[i]+=v;
		return;
	}
	if(lazy[i]){
		if(a!=b){
			tree[L(i)]+=lazy[i];
			if(!h[L(i)])tree[L(i)]+=lazy[i];
			lazy[L(i)]+=lazy[i];

			tree[R(i)]+=lazy[i];
			if(!h[R(i)])tree[R(i)]+=lazy[i];
			lazy[R(i)]+=lazy[i];
		}
		lazy[i]=0;
	}
	int m = (a+b)/2;
	update_lazy(L(i),a,m,ua,ub,v);
	update_lazy(R(i),m+1,b,ua,ub,v);
	tree[i]=tree[L(i)]+tree[R(i)];
}

int main(){
	long long n,v,q;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> v;
		L.push_back(v);
	}
	for(int i=1;i<n;i++){
		cin >> v;
		dif.push_back(L[i]-(L[i-1]+v));
	}
	tree.assign(4*n,0);
	lazy.assign(4*n,0);	
	h.assign(4*n,0);

	create_tree(0,0,n-1);

	cin >> q;
	char op;
	int a,b,l;
	while(q--){
		cin  >> op >> a >> b;
		if(op == '+'){
			l=1;
			update_lazy(0,0,n-1,a-1,l,b);
		}
		else{
			cout << rmq(0,0,n-1,a-1,b-1) << endl;
		}
	}
	return 0;
}
