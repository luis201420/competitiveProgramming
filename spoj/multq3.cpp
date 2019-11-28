#include <bits/stdc++.h>

#define L(i) (i<<1)+1
#define R(i) (i+1)<<1

using namespace std;

typedef long long ll;

vector<ll> aux(3);
vector<ll> lazy;
vector<vector<ll>> tree;

void create_tree(int i, int a, int b){
	if(a==b){
		tree[i][0]=1;
		return ;
	}
	int m=(a+b)/2;
	create_tree(L(i),a,m);
	create_tree(R(i),m+1,b);
	tree[i][0]=tree[L(i)][0]+tree[R(i)][0];
	tree[i][1]=tree[L(i)][1]+tree[R(i)][1];
	tree[i][2]=tree[L(i)][2]+tree[R(i)][2];
	return;
}

void update_tree(int i, int a, int b, int ua, int ub){
	
	if(ub<a || b<ua) return;

	if(ua<=a && b<=ub){
		aux[1]=tree[i][0];
		aux[2]=tree[i][1];
		aux[0]=tree[i][2];
		tree[i]=aux;
		lazy[i]++;
		return;
	}
	
	int m=(a+b)/2;

	if(lazy[i]){
		if(a!=b){
			aux[lazy[i]%3]     = tree[L(i)][0];
			aux[(1+lazy[i])%3] = tree[L(i)][1];
			aux[(2+lazy[i])%3] = tree[L(i)][2];
			tree[L(i)]=aux;
			lazy[L(i)]+=lazy[i];
			
			aux[lazy[i]%3]     = tree[R(i)][0];
			aux[(1+lazy[i])%3] = tree[R(i)][1];
			aux[(2+lazy[i])%3] = tree[R(i)][2];
			tree[R(i)]=aux;
			lazy[R(i)]+=lazy[i];
		}
		lazy[i]=0;
	}

	update_tree(L(i),a,m,ua,ub);
	update_tree(R(i),m+1,b,ua,ub);
	tree[i][0]=tree[L(i)][0]+tree[R(i)][0];
	tree[i][1]=tree[L(i)][1]+tree[R(i)][1];
	tree[i][2]=tree[L(i)][2]+tree[R(i)][2];
	return ;
}

ll query_tree(int i, int a, int b, int qa, int qb){
	if(qb<a || b<qa) return 0;

	if(qa<=a && b<=qb){
		return tree[i][0];
	}
	int m=(a+b)/2;

	if(lazy[i]){
		if(a!=b){
			aux[lazy[i]%3]     = tree[L(i)][0];
			aux[(1+lazy[i])%3] = tree[L(i)][1];
			aux[(2+lazy[i])%3] = tree[L(i)][2];
			tree[L(i)]=aux;
			lazy[L(i)]+=lazy[i];
			
			aux[lazy[i]%3]     = tree[R(i)][0];
			aux[(1+lazy[i])%3] = tree[R(i)][1];
			aux[(2+lazy[i])%3] = tree[R(i)][2];
			
			tree[R(i)]=aux;
			lazy[R(i)]+=lazy[i];
		}
		lazy[i]=0;
	}
	ll a1 = query_tree(L(i),a,m,qa,qb);
	ll a2 = query_tree(R(i),m+1,b,qa,qb);	
	return a1+a2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int op;
	ll n,q,l,r;
	cin >> n >> q;
	
	tree.assign(4*n,vector<ll>(3,0));
	lazy.assign(4*n,0);
	
	create_tree(0,0,n-1);
	
	while(q--){
		cin >> op >> l >> r;
		if(op==1){
			cout << query_tree(0,0,n-1,l,r) << "\n";
		}
		else{
			update_tree(0,0,n-1,l,r);
		}
	}
	return 0;
}
