#include <bits/stdc++.h>

using namespace std;

vector<long long> xs,ys;

int main(){
	int t,n;
	int x,y,i;
	long long s1,s2;
	cin >> t;
	while(t--){
		cin >> n;
		for(i=0;i<n;i++){
			cin >> x >> y;
			xs.push_back(x);
			ys.push_back(y);
		}
		s1=s2=0;
		for(i=0;i<(n-1);i++){
			s1+=(xs[i]*ys[i+1]);
			s2+=(ys[i]*xs[i+1]);
		}
		s1+=(xs[i]*ys[0]);
		s2+=(ys[i]*xs[0]);
		cout << (s1-s2)/2.0 << endl;
		xs.clear();
		ys.clear();
	}
	return 0;
}
