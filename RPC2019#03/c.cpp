#include <bits/stdc++.h>

using namespace std;

#define MM 998244253

vector<int> data;
vector<bool> used;
long long res;

void bt(int c,int o,long long ac){
	if(c==o){
		res+=ac;
		return ;
	}
	for(int i=0;i<data.size();i++){
		if(!used[i]){
			used[i]=1;
			bt(c+1,o,ac*data[i]);
			used[i]=0;
		}
	}
}

int main(){
	int n,k,v;
	cin >> n >> k;
	map<int,int> cont;
	for(int i=0;i<n;i++){
		cin >> v;
		cont[v]++;
	}
	for(auto it:cont){
		data.push_back(it.second);
	}
	res=0;
	used.assign(data.size(),0);
	bt(0,k,1);
	while(k>0){
		res/=k;
		k--;
	}
	cout << res%MM << endl;
	return 0;
}
