#include<bits/stdc++.h>

using namespace std;

vector<int> links,sizeT;

int findA(int x){
	if(x==links[x])return x;
	return links[x]=findA(links[x]);
}

bool same(int x,int y){
	return findA(x)==findA(y);
}

void unite(int x,int y){
	x=findA(x);
	y=findA(y);
	if(sizeT[x]<sizeT[y])swap(x,y);
	sizeT[x]+=sizeT[y];
	links[y]=x;
}

int main(){
	int n,m;
	int k,v,ant;
	cin >> n >> m;
	
	sizeT.assign(n,1);
	for(int i=0;i<n;i++)links.push_back(i);

	while(m--){
		cin >> k;
		ant=-1;
		while(k--){
			cin >> v;
			v--;
			if(ant!=-1 && !same(ant,v)){
				unite(ant,v);
			}
			ant=v;
		}
	}
	for(int i=0;i<n;i++){
		if(i!=0)cout << " ";
		cout << sizeT[findA(i)];
	}
	cout << endl;
	return 0;
}
