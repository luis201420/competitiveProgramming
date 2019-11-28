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
	int n,v;
	cin >> n;
	vector<int> pos(n);
	A.resize(n);
	for(int i=0;i<n;i++){
		cin >> v;
		pos[v-1] = i;
		A[i] = i;
	}

	tree.assign(4*n,0);
	lazy.assign(4*n,0);
	create(0,0,n-1);
	
	int x,y;

	x=0;y=n-1;

	int posC;

	while(x<y){
		posC = rmq(0,0,n-1,pos[x],pos[x]);
		//cerr << x << " " << pos[x]<<" "<< posC << endl;
		cout << posC-x << endl;
		//+1
		update(0,0,n-1,0,pos[x]-1,1);
		posC = rmq(0,0,n-1,pos[y],pos[y]);
		cout << y-posC << endl;
		update(0,0,n-1,pos[y]+1,n-1,-1);
		x++;
		y--;
	}
	if(x==y){
		posC = rmq(0,0,n,pos[x],pos[x]);
		cout << posC-x << endl;
	}

	return 0;
}
