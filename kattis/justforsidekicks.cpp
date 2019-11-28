#include<bits/stdc++.h>

#define L(i) (i<<1)+1
#define R(i) (i+1)<<1

using namespace std;

typedef long long ll;

vector<ll> values(6);
string types;
vector<vector<ll>>tree;

void create(int i, int a, int b){
	if(a==b){
		tree[i][(types[a]-1)-'0']++;
		return;
	}
	int m=(a+b)/2;
	create(L(i),a,m);
	create(R(i),m+1,b);
	for(int j=0;j<6;j++){
		tree[i][j]=tree[L(i)][j]+tree[R(i)][j];
	}
	return;
}

void update(int i, int a, int b, int ua, int ub, char v){
	if(ub<a || b<ua) return;
	if(ua <= a && b <= ub){
		tree[i][(types[a]-1)-'0']--;
		types[a]=v;
		tree[i][(types[a]-1)-'0']++;
		return;
	}
	int m=(a+b)/2;
	update(L(i),a,m,ua,ub,v);
	update(R(i),m+1,b,ua,ub,v);
	for(int j=0;j<6;j++){
		tree[i][j]=tree[L(i)][j]+tree[R(i)][j];
	}
	return;
}

vector<ll> rmq(int i, int a, int b, int qa, int qb){
	if(qb < a || b < qa) return vector<ll>(6,0);
	if(qa<=a && b<=qb){
		return tree[i];
	}
	int m=(a+b)/2;
	vector<ll> m1 = rmq(L(i),a,m,qa,qb);
	vector<ll> m2 = rmq(R(i),m+1,b,qa,qb);
	for(int j=0;j<6;j++){
		m1[j]+=m2[j];
	}
	return m1;
}

int main(){
	ll n,q,k,v,res;
	ll op;
	char p;
	cin >> n >> q;
	vector<ll> ans;
	for(int i=0;i<6;i++){
		cin >> values[i];
	}
	
	cin >> types;

	tree.assign(4*n,vector<ll>(6,0));
	create(0,0,n-1);

	while(q--){
		cin >> op;
		if(op == 1){
			cin >> k >> p;
			update(0,0,n-1,k-1,k-1,p);
		}
		else if(op == 2){
			cin >> k >> v;
			values[k-1]=v;
		}
		else{
			cin >> k >> v;
			ans=rmq(0,0,n-1,k-1,v-1);
			res=0;
			for(int i=0;i<6;i++){
				res+=values[i]*ans[i];
			}
			cout << res << endl;
		}
	}
	return 0;
}
