#include <bits/stdc++.h>

using namespace std;

vector<int> ns;
int n;

int bs(int x){
	int a=0, b=ns.size()-1;
	while(a<=b){
		int k=(a+b)/2;
		if(ns[k]==x)return k;
		if(ns[k]<x)a=k+1;
		else b=k-1;
	}
	return a;
}

int main(){
	int v,cont=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> v;
		if(i!=0 && v < ns[ns.size()-1]){
			//cerr << v << endl;
			cont+=2;
			int aux = v;
			int id = upper_bound(ns.begin(),ns.end(),v)-ns.begin();
			for(;i<n;i++){
				cin >> v;
				if(v<aux || v>ns[id]){i++;break;}
				aux=v;
			}
			if(i<n)ns.push_back(v);

		}
		else ns.push_back(v);
		cerr << v << endl;
	}
	cout << cont << endl;
	return 0;
}
