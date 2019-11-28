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


char get(int n, int x, int y) {
	x %= 2 * n - 1;
	y %= 2 * n - 1;
	int dx = abs(n - 1 - x);
	int dy = abs(n - 1 - y);
	if (dx + dy >= n) return '.';
	return (dx + dy) % 26 + 'a';
}

int main(){FIN
	ll n,lx,ly,rx,ry,cont=1,aux;
	while( cin >> n >> lx >> ly >> rx >> ry){
		
		if(n==0) break;
		
		cout << "Case " << cont++ << ":\n" ;

		fore(x,lx,rx+1){
			fore(y,ly,ry+1) cout << get(n,x,y);
			cout << "\n";
		}
	}
	return 0;
}
