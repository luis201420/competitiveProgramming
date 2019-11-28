#include <bits/stdc++.h>
 
#define L(i) (i<<1)+1
#define R(i) (i+1)<<1
 
using namespace std;
 
typedef long long ll;
 
vector<ll> tree,lazy;
 
void create(ll i, ll a, ll b){
	if(a==b){
		tree[i]=0;
		return ;
	}
	ll m = (a+b)/2;
	create(L(i),a,m);
	create(R(i),m+1,b);
	tree[i]=tree[L(i)]+tree[R(i)];	
}
 
void update(ll i, ll a, ll b, ll ua, ll ub, ll v){
	if(ub < a || b < ua) return;
	
	if(ua <= a && b <= ub){
		tree[i]+=(((b-a)+1)*v);
		lazy[i]+=v;
		return ;
	}
	
	ll m = (a+b)/2;
 
	if(lazy[i]>0){
		if(a!=b){
			tree[L(i)] += (lazy[i]*((m-a)+1));
			lazy[L(i)] += lazy[i];
 
			tree[R(i)] += (lazy[i]*((b-(m+1))+1));
			lazy[R(i)] += lazy[i];
		}
		lazy[i]=0;
	}
 
	update(L(i),a,m,ua,ub,v);
	update(R(i),m+1,b,ua,ub,v);
	tree[i]=tree[L(i)]+tree[R(i)];
}
 
ll rmq(ll i, ll a, ll b, ll qa, ll qb){
	if(qb < a || b < qa) return 0;
 
	if(qa <= a && b <= qb){
		return tree[i];
	}
 
	ll m = (a+b)/2;
 
	if(lazy[i]>0){
		if(a!=b){
			tree[L(i)] += (lazy[i]*((m-a)+1));
			lazy[L(i)] += lazy[i];
 
			tree[R(i)] += (lazy[i]*((b-(m+1))+1));
			lazy[R(i)] += lazy[i];
		}
		lazy[i]=0;
	}
 
	ll v1 = rmq(L(i),a,m,qa,qb);
	ll v2 = rmq(R(i),m+1,b,qa,qb);
	return v1+v2;
}
 
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
 
	ll t, v;
	ll n, c;
	cin >> t;
 
	ll op,a,b;
 
	while(t--){
		cin >> n >> c;
 
		tree.assign(4*n,0);
		lazy.assign(4*n,0);
 
		create(0,0,n-1);
 
		while(c--){
			cin >> op >> a >> b;
			if(op == 0){
				cin >> v;
				update(0,0,n-1,a-1,b-1,v);
			}
			else{
				cout << rmq(0,0,n-1,a-1,b-1) << endl;
			}
		}
	}
	return 0;
}

