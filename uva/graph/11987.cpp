#include <bits/stdc++.h>

using namespace std;

vector<long long> link,sizeT,sumT;

int findA(int x){
	if(x == link[x]) return x;
	return link[x] = findA(link[x]);
}

bool same(int x,int y){
	return findA(x)==findA(y);
}

void uniteS(int x,int y){
	x=findA(x);
	y=findA(y);
	if(sizeT[x]<sizeT[y])swap(x,y);
	sizeT[x]+=sizeT[y];
	sumT[x]+=sumT[y];
	link[y]=x;
}

void uniteU(int x,int y){
	sizeT[findA(x)]--;
	sumT[findA(x)]-=(x+1);
	link[x]=findA(y);
	sumT[findA(y)]+=(x+1);
	sizeT[findA(y)]++;
}

int main(){
	int op;
	long long n,m,a,b;
	while(cin >> n >> m){
		sizeT.assign(n,1);
		for(int i=0;i<n;i++){
			link.push_back(i);
			sumT.push_back(i+1);
		}
		while(m--){
			cin >> op;
			if(op == 1){
				cin >> a >> b;
				if(!same(a-1,b-1))uniteS(a-1,b-1);
			}
			else if(op == 2){
				cin >> a >> b;
				if(!same(a-1,b-1))uniteU(a-1,b-1);
			}
			else{
				cin >> a;
				cout << sizeT[findA(a-1)] << " " <<  sumT[findA(a-1)] << endl;
			}
		}
		link.clear();
	}
	return 0;
}
