#include <bits/stdc++.h>

using namespace std;

vector<int> zeros,negat,s;
int n,k,a,v,ans1,ans2,aux1,aux2,b;
char op;

void update(int pos,int value){
	for(;pos<=n;pos+=(pos&-pos)){
		if(value<0)negat[pos]++;
		if(value == 0) zeros[pos]++;
	}
}

void rem(int k){
	int val = s[k];
	for(;k<=n;k+=(k&-k)){
		if(val<0)negat[k]--;
		if(val==0)zeros[k]--;
	}
}

void query(int k,int &a,int &b){
	a=0;
	b=0;
	for(;k>0;k-=(k&-k)){
		a+=negat[k];
		b+=zeros[k];
	}
}

int main(){
	while(cin >> n >> k){

		zeros.assign(n+1,0);
		negat = zeros;
		s = zeros;

		for(int i=1;i<=n;i++){
			cin >> v;
			update(i,v);
			s[i] = v;
		}

		while(k--){
			cin >> op >> a >> b;
			if(op == 'C'){
				rem(a);
				update(a,b);
				s[a]=b;
			}
			else{
				query(b,ans1,ans2);
				query(a-1,aux1,aux2);
				//cerr << ans1 << "." << aux1 << " " << ans2 << "." << aux2 << endl;
				ans1-=aux1;ans2-=aux2;
				if(ans2>0)cout << "0";
				else if(ans1&1)cout << "-";
				else cout << "+";
			}
		}
		cout << endl;
	}
	return 0;
}
