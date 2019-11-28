#include <bits/stdc++.h>

using namespace std;

vector<bool> used,sol;
vector<int> l;
int res,tmp;

int n,m,v;

void subsets(int v){
	if(v==used.size()){
		tmp=0;
		for(int i=0;i<l.size();i++)
			if(used[i])tmp+=l[i];
		if(res<tmp && tmp<=n){
			res=tmp;
			sol=used;
		}
		return;
	}
	used[v]=1;
	subsets(v+1);
	used[v]=0;
	subsets(v+1);
}

int main(){

	while(cin >> n >> m){
		used.assign(m,0);
		while(m--){
			cin >> v;
			l.push_back(v);
		}
		res=0;
		subsets(0);
		for(int i=0;i<l.size();i++){
			if(sol[i])cout<<l[i] << " ";
		}
		cout <<"sum:"<< res << endl;
		l.clear();
	}
	return 0;
}
