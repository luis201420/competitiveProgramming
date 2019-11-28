#include <bits/stdc++.h>

#define FIN ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define pb push_back
#define ALL(s) s.begin(),s.end()

using namespace std;

typedef long long ll;

int main(){
	FIN
	ll q,n,k,v,cont;
	cin >> q;
	vector<bool> ns;
	while(q--){
		cin >> n >> k;
		ns.resize(n);
		cont=0;
		for(int i=0;i<n;i++){
			cin >> v;
			ns[i]=v&1;
			if(v&1)cont++;
		}
		if(cont>=k && (cont-k)%2==0){
			cout << "YES\n";
			for(int i=0;i<n;i++){
				
				if(k==1)break;

				if(ns[i]){
					cout << i+1 << " ";
					k--;
				}	
			}
			cout << n << "\n";
		}
		else cout << "NO\n";
	}
	return 0;
}
