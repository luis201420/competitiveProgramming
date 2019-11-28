#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

#define SQR(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 11

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<string> vstr;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<vbool> vvbool;

void addOne(string &p, ll n){
	ll c = SZ(p)-1;
	while(c>=0 && p[c]=='9'){
		p[c]='0';
		c--;
	}
	if(c<0){
		p="1"+string(n-1,'0');
		cout << p;
	}
	else{
		p[c] += 1;
	}
}

int main(){FIN
	ll n,v,j,cont1,cont2;
	string s,p;
	bool ver;

	cin >> n;
	cin >> s;

	if(SZ(s)%n==0){
		v = SZ(s)/n;
		p = s.substr(0,n);
		ver = 0;
		cont1 = 0;
		fore(i,0,n){
			j = i;
			cont2=0;
			while(j<SZ(s)){
				if(s[j]==s[i])cont2++;
				if(s[j]>s[i]){
					ver=1;
					break;
				}
				j+=n;
			}
			if(cont2!=v || ver)break;
			cont1+=cont2;
		}
		if(ver || cont1 == SZ(s))addOne(p,n);
		fore(i,0,v){
			cout << p;
		}
		cout << "\n";
	}
	else{
		v = SZ(s)/n;
		v++;
		p = "1" + string(n-1,'0');
		fore(i,0,v){
			cout << p;
		}
		cout << "\n";
	}
	return 0;
}
