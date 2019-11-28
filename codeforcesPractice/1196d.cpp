#include <bits/stdc++.h>

#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_bask
#define ALL(s) s.begin(),s.end()
#define SZ(s) s.size()

using namespace std;

typedef long long ll;

const string m = "RGB";

int main(){FIN
	ll q,n,k,ans,ant,cont;
	string s;
	cin >> q;
	while(q--){
		cin >> n >> k;
		cin >> s;
		ans = 1e9;
		for(int i=0;i<3;i++){
			cont=0;
			for(int j=0;j<n;j++){
				if(j>=k){
					ans = min(ans,cont);
					ant = j-k;
					if(s[ant]!=m[(i+ant)%3])cont--;
				}
				if(s[j]!=m[(i+j)%3])cont++;
			}
			ans=min(ans,cont);
		}
		cout << ans << "\n";
	}
	return 0;
}
