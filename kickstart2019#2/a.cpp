#include <bits/stdc++.h>
#define L(i) (i<<1)+1
#define R(i) (i+1)<<1

using namespace std;

typedef vector<long long> vi;

const vi zeros(26,0);
string s;
vector<vi> tree;

void create_tree(int i,int a, int b){
	if(a==b){
		tree[i][s[a]-'A']++;
		return;
	}
	int m=(a+b)/2;
	create_tree(L(i),a,m);
	create_tree(R(i),m+1,b);
	for(int p=0;p<26;p++){
		tree[i][p]=tree[L(i)][p]+tree[R(i)][p];
	}
}
vi rmq(int i, int a, int b, int qa, int qb){
	if(qb<a || b<qa) return zeros;
	if(qa<=a && b <=qb){
		return tree[i];
	}
	int m=(a+b)/2;
	vi v1 = rmq(L(i),a,m,qa,qb);
	vi v2 = rmq(R(i),m+1,b,qa,qb);
	for(int p=0;p<26;p++){
		v1[p]+=v2[p];
	}
	return v1;
}

int main(){
	vi query;
	int t,cont1,cont2;
	int n,q,l,r,ans;
	cin >> t;
	for(int c=1;c<=t;c++){
		cin >> n >> q;
		cin >> s;
		tree.assign((4*s.size()),vi(26,0));
		create_tree(0,0,s.size()-1);
		ans=0;
		while(q--){
			cin >> l >> r;
			query=rmq(0,0,s.size()-1,l-1,r-1);
			cont1=cont2=0;
			for(int i=0;i<query.size();i++){
				if(query[i]&1)cont1++;
				else if(query[i]!=0)cont2++;
			}
			if(((r-l)+1)&1){
				if(cont1==1) ans++;
			}
			else{
				if(cont1==0) ans++;
			}
		}
		cout << "Case #"<<c << ": "<<ans << endl;
	}
	return 0;
}
