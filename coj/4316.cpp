#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);//cout.tie(0);
	int n;
	ll s;
	vector<ll> ns;
	while(cin>> n >> s){
		ns.resize(n);
		for(int e=0;e<n;e++){
			cin >> ns[e];
		}
		ll r=0;
		int i=0,j=0;
		while(i<n){
			while(j<n && r<s){r+=ns[j++];}
			if(r==s)break;
			else{
				r-=ns[i++];
			}
			//cerr << r << endl;
		}
		if(s!=r) printf("-1\n");
		else printf("%d %d\n",i+1,j);
	}
	return 0;
}
