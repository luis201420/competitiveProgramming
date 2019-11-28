#include <bits/stdc++.h>

#define L(i) (i<<1)+1
#define R(i) (i+1)<<1

using namespace std;

typedef long long ll;

vector<ll> tree,lazy,A,B;

/*
void create_tree(){
}
*/

void update_tree(int i, int a, int b, int ua, int ub){
	if(ub<a || b<ua) return;

	if(ua<=a && b<=ub){
		//lazyModificaded
		lazy[i]++;
		//TreeValueModificaded
		tree[i]+=((a-b)+1);
		return;
	}

	int m = (a+b)/2;

	if(lazy[i]){
		//update lazy children
		if(a!=b){
			tree[L(i)]+=((m-a)+1)*lazy[i];
			lazy[L(i)]+=lazy[i];
			tree[R(i)]+=(b-m)*lazy[i];
			lazy[R(i)]+=lazy[i];
		}
		lazy[i]=0;
	}
	update_tree(L(i),a,m,ua,ub);
	update_tree(R(i),m+1,b,ua,ub);
	tree[i]=tree[L(i)]+tree[R(i)];
}

ll query_tree(int i, int a, int b, int qa, int qb){
	if(qb<a || b<qa) return 0;

	if(qa <= a && b <= qb){
		return tree[i];
	}
	
	int m = (a+b)/2;
	if(lazy[i]){
		if(a!=b){
			//update lazy childen
			tree[L(i)]+=((m-a)+1)*lazy[i];
			lazy[L(i)]+=lazy[i];
			tree[R(i)]+=(b-m)*lazy[i];
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
	cin.tie(0);

	ll n, q;
	cin >> n >> q;
	
	A.resize(n);
	
	for(ll i=0;i<n;i++)cin >> A[i];
	
	ll l,r;
	tree.assign(4*n,0);
	lazy.assign(4*n,0);

	while(q--){
		cin >> l >> r;
		l--;r--;
		update_tree(0,0,n-1,l,r);
	}

	for(ll i=0;i<n;i++){
		B.push_back(query_tree(0,0,n-1,i,i));
		//cerr << B[i] << endl;
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());

	ll ans=0;
	for(ll i=0;i<n;i++){
		ans+=(A[i]*B[i]);
	}
	cout << ans << "\n";
	return 0;
}
