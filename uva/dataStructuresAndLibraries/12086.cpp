#include <bits/stdc++.h>

using namespace std;

long long n,v,a,b;
vector<long long> tree,s;

void update(long long pos, long long val){
	for(;pos<=n;pos+=(pos&-pos)){
		tree[pos]+=val;
	}
}

long long query(long long k){
	long long res = 0;
	for(;k>0;k-=(k&-k)){
		res+=tree[k];
	}
	return res;
}

int main(){
	string op;
	int cont = 1;
	while(cin >> n){
		if(n==0)break;

		tree.assign(n+1,0);
		s = tree;

		for(long long i=1;i<=n;i++){
			cin >> v;
			update(i,v);
			s[i]=v;
		}
		if(cont != 1) cout << endl;
		cout << "Case "<<cont<<":"<<endl;
		while(cin >> op){
			if(op == "END")break;

			cin >> a >> b;
			if(op == "S"){
				update(a,(b-s[a]));
				s[a]=b;
			}
			else{
				//cout << a << " " << b << ": ";
				cout << query(b)-query(a-1) << endl;
			}
		}
		cont++;
	}
	return 0;
}
