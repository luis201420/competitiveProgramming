#include <bits/stdc++.h>

using namespace std;

vector<int> links,sizes;

int finds(int x){
	if(x==links[x]) return x;
	return links[x]=finds(links[x]);
}

bool same(int x, int y){
	return finds(x) == finds(y);
}

void unite(int x, int y){
	x = finds(x);
	y = finds(y);
	if(sizes[x]<sizes[y])swap(x,y);
	sizes[x]+=sizes[y];
	links[y]=x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin >> n >> q;
	for(int i=0;i<n;i++){
		links.push_back(i);
	}
	sizes.assign(n,1);
	int a,b;
	char op;
	while(q--){
		cin >> op >> a >> b;
		if(op=='='){
			if(!same(a,b))
				unite(a,b);
		}
		else{
			if(same(a,b))cout << "yes";
			else cout << "no";
			cout << endl;
		}
	}
	return 0;
}
