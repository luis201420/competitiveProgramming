#include <bits/stdc++.h>

#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define SZ(s) s.size()

using namespace std;

typedef long long ll;

int main(){FIN
	
	ll q,n,X,Y,Xmin,Xmax,Ymin,Ymax;
	bool f1,f2,f3,f4;
	vector<ll> xr,xl,yr,yl;

	cin >> q;
	while(q--){
		cin >> n;
		
		xr.pb(100000);
		xl.pb(-100000);
		yr.pb(100000);
		yl.pb(-100000);

		for(int i=0;i<n;i++){
			cin >> X >> Y;
			cin >> f1 >> f2 >> f3 >> f4;
			if(!f1) xl.pb(X);
			if(!f2) yr.pb(Y);
			if(!f3) xr.pb(X);
			if(!f4) yl.pb(Y);
		}
		sort(ALL(xr));
		sort(ALL(xl));
		sort(ALL(yr));
		sort(ALL(yl));
		
		Xmin = xl[SZ(xl)-1];
		Xmax = xr[0];

		Ymin = yl[SZ(yl)-1];
		Ymax = yr[0];

		//cerr << SZ(xr) << " " << SZ(xl) << "\n";

		//cerr << Xmax << " " << Xmin << "\n";
		//cerr << Ymax << " " << Ymin << "\n";
		
		if((Xmin <= Xmax) && (Ymin <= Ymax) ){
			cout <<"1 "<< Xmin << " " << Ymin << "\n";
		}
		else cout << "0\n";

		xr.clear();
		xl.clear();
		yl.clear();
		yr.clear();
	}
	return 0;
}
