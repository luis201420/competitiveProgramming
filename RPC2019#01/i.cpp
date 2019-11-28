#include <bits/stdc++.h>

using namespace std;

bool myComp(const pair<long long,long long> &a,const pair<long long,long long> &b){
	if(a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}

int main(){
	
	long long n,k,v;
	vector<pair<long long,long long>> res;
	vector<long long> A,B;
	vector<bool> ver(100000001,0);
	scanf("%lld %lld",&n,&k);
	while(n--){
		scanf("%lld",&v);
		A.push_back(v);
		ver[v]=1;
	}

	sort(A.begin(),A.end());
	long long cont;
	while(k--){
		scanf("%lld",&v);
		cont=0;
		//aux=ver;
		for(int i=0;i<A.size();i++){
			if((v-A[i])>100000000)continue;
			if(A[i]>(v/2))break;
			if(ver[(v-A[i])] && A[i]!=((v-A[i]))){
				//cerr << A[i] << " " << (v-A[i]) << endl;
				//ver[(v-A[i])]=0;
				//ver[A[i]]==0;
				cont++;
			}
		}
		//ver=aux;
		res.push_back({v,cont});
	}
	sort(res.begin(),res.end(),myComp);
	for(int i=0;i<res.size();i++){
		printf("%lld %lld\n",res[i].first,res[i].second);
		//cout << res[i].first << " " << res[i].second << endl;
	}
	
	return 0;
}
