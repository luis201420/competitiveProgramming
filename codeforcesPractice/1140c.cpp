#include<bits/stdc++.h>

using namespace std;

bool mycomp2(const pair<int,int> &a, const pair<int,int> &b){
	return a.second > b.second;
}

bool mycomp1(const pair<int,int> &a, const pair<int,int> &b){
	return a.first > b.first;
}

int main(){
	int n,k;
	int a,b;
	cin >> n >> k;
	vector<pair<int,int>> ns;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		ns.push_back({a,b});
	}
	sort(ns.begin(),ns.end(),mycomp2);
	/*int i=1;
	int res1 = 0;
	int m = ns[0].second;
	int f = ns[0].first;
	while(i<=k && (f*m)>res1){
		res1=f*m;
		f+=ns[i].first;
		m=ns[i].second;
		i++;
	}
	sort(ns.begin(),ns.end(),mycomp1);
	i=1;
	int res2 = 0;
	m = ns[0].second;
	f = ns[0].first;
	while(i<=k && (f*m)>res2){
		res2=f*m;
		f+=ns[i].first;
		m=min(m,ns[i].second);
		i++;
	}
	cout << max(res1,res2) << endl;
	*/
	int f,m,res=0,cont,j;
	for(int i=0;i<n;i++){
		f=ns[i].first;
		m=ns[i].second;
		j=i+1;
		cont=0;
		while(j<n && cont<k){
			res=max(res,f*m);
			f+=ns[j].first;
			m=min(m,ns[j].second);
			j++;
			cont++;
		}
	}
	cout << res << endl;
	return 0;
}
