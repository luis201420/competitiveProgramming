#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll v,cont,v1,v2,v3,s;
vector<ll> tree;
int n;

void update(int pos,ll val){
	for(;pos<=n;pos+=(pos&-pos)){
		tree[pos]+=val;
	}
}

ll query(int k){
	ll res = 0;
	for(;k>0;k-=(k&-k)){
		res+=tree[k];
	}
	return res;
}

int main(){
	cin >> n;
	tree.assign(n+1,0);
	for(int i=1;i<=n;i++){
		cin >> v;
		update(i,v);
	}
	s=query(n);
	cont = 0;
	if(s%3==0){
		for(int i=1;i<n;i++){
			v1=query(i);
			if(v1==(s/3)){
				for(int j=i+1;j<n;j++){
					v2=query(j)-v1;
					v3=s-v2-v1;
					//cerr << v1 << " " << v2 << " " << v3 << endl;
					if(v1==v2 && v2 == v3)cont++;
				}
			}
		}
	}
	cout << cont << endl;
	return 0;
}
