#include <bits/stdc++.h>

#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ALL(s) s.begin(),s.end()
#define SZ(s) s.size()
#define pb push_back

using namespace std;

typedef long long ll;

int main(){FIN
	ll q,n,ans;
	string s;
	cin >> q;
	for(ll t=1;t<=q;t++){
		cin >> n;
		cin >> s;
		ans=0;
		for(int i=0;i<n;i++){
			if(s[i]=='.'){
				ans++;
				i+=2;
			}
		}
		cout << "Case " << t << ": "<< ans << "\n";
	}
	return 0;
}
