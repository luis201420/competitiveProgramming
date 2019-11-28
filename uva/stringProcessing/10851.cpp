#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vstr;

char b(int i,char c){
	if(int(c/pow(2,i))&1) return '\\';
	else return '/';
}

int main(){FIN
	
	ll q,l;
	cin >> q;
	
	string line;
	vstr crip;
	bool ver;
	
	getline(cin,line);
	
	while(q--){
		l=0;
		while(getline(cin,line)){
			if(SZ(line)==0)break;
			crip.pb(line);
			l=SZ(line);
		}

		fore(j,1,l-1){
			fore(c,32,127){
				ver=1;
				fore(i,1,9){
					if(b(i-1,c)!=crip[i][j])ver=0;
				}
				if(ver){
					cout << char(c);
					break;
				}
			}
			
		}
		cout << "\n";
		crip.clear();
	}
	return 0;
}
