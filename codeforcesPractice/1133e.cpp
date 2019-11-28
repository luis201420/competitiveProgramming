#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> ns(n);
	for(int i=0;i<n;i++)cin >> ns[i];
	sort(ns.begin(),ns.end());
	int f,l,r;
	vector<bool> used(n,0);
	long long res=0;
	while(k--){
		int aux=0;
		for(int i=0;i<n;i++){
			if(used[i])continue;
			f = (upper_bound(ns.begin(),ns.end(),ns[i]+5)-ns.begin());
			while(f>i && used[f-1])f--;
			if(aux<(f-i)){
				aux=f-i;
				l=i;r=f;
			}
		}
		res+=aux;
		for(;l<r;l++)used[l]=1;
	}
	cout << res << endl;
	return 0;
}
