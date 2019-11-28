#include <bits/stdc++.h>

#define FIN ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define pb push_bask
#define ALL(s) s.begin(),s.end()

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){
	FIN;
	ll t,n,m,k,bag,aux;
	cin >> t;
	vll col;
	while(t--){
		cin >> n >> m >> k;
		col.resize(n);
		for(int i=0;i<n;i++)cin >> col[i];
		bag=m;
		bool ans = 1;
		for(int i=0;i<(n-1);i++){
			if((col[i+1]-col[i])<k){
				aux=(k-col[i+1]+col[i]);
				if(aux>col[i]) aux=col[i];
				bag+=aux;
			}
			else if((col[i+1]-col[i])>k){
				aux = col[i+1]-col[i]-k;
				if(aux<=bag)bag-=aux;
				else{ans = 0;break;}
			}
		}
		if(ans) cout << "YES" << "\n";
		else cout<< "NO" << "\n";
	}
	return 0;
}
