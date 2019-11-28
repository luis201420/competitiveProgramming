#include <bits/stdc++.h>

using namespace std;

struct MyStr{
	int a,b,mm;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,h,m;
	int l,r,hm;
	cin >> n >> h >> m;
	vector<MyStr> rest;
	for(int i=0;i<m;i++){
		cin >> l >> r >> hm;
		rest.push_back({l,r,hm});
	}
	int aux,res=0;
	for(int i=1;i<=n;i++){
		aux=h;
		for(int j=0;j<rest.size();j++){
			if(rest[j].a<=i && i<=rest[j].b)
				aux=min(aux,rest[j].mm);
		}
		res+=(aux*aux);
	}
	cout << res << endl;
	return 0;
}
