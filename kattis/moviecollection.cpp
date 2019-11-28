#include <bits/stdc++.h>

#define L(i) (i<<1)+1
#define R(i) (i+1)<<1

using namespace std;

vector<int> tree, lazy;
vector<int> A;

void create(int i, int a, int b ){
	if(a==b){
		tree[i]=A[a];
		return ;
	}
	int m=(a+b)/2;
	create(L(i),a,m);
	create(R(i),m+1,b);
	tree[i] = tree[L(i)] + tree[R(i)];
}

void update(int i, int a, int b, int ua, int ub, int val){
	if(ub<a || b<ua) return ;
	
	if(ua<=a && b<=ub){
		lazy[i]+=val;
		tree[i]+=val;
		return;
	}
	//Lazy
	if(lazy[i]!=0){
		if(a!=b){
			lazy[L(i)]+=lazy[i];
			tree[L(i)]+=lazy[i];
			lazy[R(i)]+=lazy[i];
			tree[R(i)]+=lazy[i];
		}
		lazy[i]=0;
	}
	int m=(a+b)/2;
	update(L(i),a,m,ua,ub,val);
	update(R(i),m+1,b,ua,ub,val);
	tree[i]=tree[L(i)]+tree[R(i)];
}

int rmq(int i, int a, int b, int qa, int qb){
	if(qb < a || b < qa) return 0;
	if(qa<=a && b <= qb){
		return tree[i];
	}
	if(lazy[i] != 0){
		if(a!=b){
			lazy[L(i)]+=lazy[i];
			tree[L(i)]+=lazy[i];
			lazy[R(i)]+=lazy[i];
			tree[R(i)]+=lazy[i];
		}
		lazy[i]=0;
	}
	int m = (a+b)/2;
	int v1 = rmq(L(i),a,m,qa,qb);
	int v2 = rmq(R(i),m+1,b,qa,qb);
	return v1+v2;
}

int main(){
	vector<int> pos;
	int t,n,r,ac,q;
	cin >> t;
	while(t--){
		cin >> n >> r;

		A.resize(n+r);
		pos.resize(n);
		
		for(int i=0;i<n;i++){
			pos[i]=n-i-1;
		}
		
		ac=n-1;
		
		for(int i=0;i<(n+r);i++){
			A[i]=ac--;
			//cerr << A[i] << endl;
		}
		
		tree.assign(4*A.size(),0);
		lazy.assign(4*A.size(),0);

		create(0,0,A.size()-1);

		for(int i=0;i<r;i++){
			cin >> q;
			if(i!=0)cout << " ";
			cout << rmq(0,0,A.size()-1,pos[q-1],pos[q-1]);
			update(0,0,A.size()-1,pos[q-1],A.size()-1,1);
			pos[q-1]=n++;
		}
		cout << endl;
	}

	return 0;
}
