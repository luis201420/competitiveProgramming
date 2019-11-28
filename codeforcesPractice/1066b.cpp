#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,r,pi,pf;
	vector<int> h,v,l;
	cin >> n >> r;
	h.resize(n);
	v.assign(n,0);
	for(int i=0;i<n;i++){
		cin >> h[i];
		if(h[i]>0){
			l.push_back(i);
			pi = (i-r+1);
			pf = (i+r-1);
			for(int j=max(0,pi);j<=min(n-1,pf);j++){
				v[j]++;
			}
		}
	}
	
	bool ver=1;
	for(int i=0;i<v.size();i++){
		if(v[i]==0){
			ver=0;
			break;
		}
	}

	if(ver){
		int ans = l.size();
		for(int i=0;i<l.size();i++){
			pi = (l[i]-r+1);
			pf = (l[i]+r-1);
			ver=1;
			for(int j=max(0,pi);j<=min(n-1,pf);j++){
				if(v[j]==1){
					ver=0;
					break;
				}	
			}
			if(ver){
				for(int j=max(0,pi);j<=min(n-1,pf);j++){
					v[j]--;	
				}
				ans--;
			}
		}
		cout << ans <<endl;
	}
	else{
		cout << -1 << endl;
	}
	return 0;
}
