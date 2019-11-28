#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<ll> tree;
int n;

void add(ll k, ll v){
	while(k<=n){
		tree[k]+=v;
		k+=k&-k;
	}
}
ll sum(int k){
	ll r=0;
	while(k>=1){
		r+=tree[k];
		k-=k&-k;
	}
	return r;
}

ll query(ll a, ll b){
	return sum(b)-sum(a-1);
}

int main(){
	ll k,l,r,pos;
	char op;
	cin >> n >> k;
	vector<bool> val(n,0);
	tree.assign(n+1,0);
	/*for(int i=1;i<=n;i++){
		add(i,0);
	}*/
	while(k--){
		cin >> op;
		if(op == 'C'){
			cin >> l >> r;
			cout << query(l,r) << endl;
		}
		else{
			cin >> pos;
			if(val[pos-1])add(pos,-1);
			else add(pos,1);
			val[pos-1]= val[pos-1]^1;
		}
	}
	return 0;
}
