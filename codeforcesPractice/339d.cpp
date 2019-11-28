#include <bits/stdc++.h>

#define L(i) (i<<1)+1
#define R(i) (i+1)<<1

using namespace std;

typedef long long ll;

vector<ll> tree,A;

void create_tree(int i, int a, int b, int l){
	if(a==b){
		tree[i]=A[a];
		return ;
	}
	int m = (a+b)/2;
	create_tree(L(i),a,m,l+1);
	create_tree(R(i),m+1,b,l+1);
	if(l&1)tree[i] = tree[L(i)] ^ tree[R(i)];
	else tree[i] = tree[L(i)] | tree[R(i)];
}

void update_tree(int i, int a, int b, int p, int v, int l){
	if(p<a || b<p) return;

	if(p<=a && b <= p){
		tree[i] = v;
		return ;
	}
	
	int m = (a+b)/2;
	
	update_tree(L(i),a,m,p,v,l+1);
	update_tree(R(i),m+1,b,p,v,l+1);

	if(l&1)tree[i] = tree[L(i)] ^ tree[R(i)];
	else tree[i] = tree[L(i)] | tree[R(i)];
}

/*
void query_tree(int i, int a, int b){

}*/

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n,m,P,V;
	cin >> n >> m;
	int ini;
	if(n&1) ini=0;
	else ini=1;
	n = (1<<n);
	A.resize(n);
	for(ll i=0;i<n;i++)cin >> A[i];
	tree.assign(4*n,0);
	create_tree(0,0,n-1,ini);
	
	//cerr << tree[0] << endl;

	while(m--){
		cin >> P >> V;
		P--;
		update_tree(0,0,n-1,P,V,ini);
		//A[P]=V;
		cout << tree[0] << "\n";
	}
	return 0;
}
