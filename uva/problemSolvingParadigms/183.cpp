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

vvbool bm;
string ans,s;
ll n,m,posD;

bool ver(ll xi, ll yi, ll xf, ll yf){
	bool f = bm[xi][yi];
	fore(i,xi,xf){
		fore(j,yi,yf){
			if((f && !bm[i][j])||(!f && bm[i][j]))return 0;
		}
	}
	return 1;
}

void comp(ll xi, ll yi, ll xf, ll yf){
	//DBG(xi);DBG(yi);DBG(xf);DBG(yf);
	if(xi>=xf || yi>=yf || xi>=n || yi>=m)return;
	if(ver(xi,yi,xf,yf)){
		if(bm[xi][yi])ans+='1';
		else ans+='0';
		//DBG(ans);
		return;
	}
	ans+='D';
	ll xm = (xf+xi+1)/2;
	ll ym = (yf+yi+1)/2;
	comp(xi,yi,xm,ym);
	comp(xi,ym,xm,yf);
	comp(xm,yi,xf,ym);
	comp(xm,ym,xf,yf);
}

void fill(ll xi, ll yi, ll xf, ll yf,bool vv){
	fore(i,xi,xf){
		fore(j,yi,yf){
			bm[i][j]=vv;
		}
	}

}
char aa;

void decomp(ll xi, ll yi, ll xf, ll yf,char cc){
	if(xi>=xf || yi>=yf || xi>=n || yi>=m){
		return;
	}
	aa = cin.get();
	posD++;
	s+=aa;
	//DBG(cc);
	if(s[posD]!='D'){
		fill(xi,yi,xf,yf,(s[posD]=='1'));
		return;
	}
	ll xm = (xf+xi+1)/2;
	ll ym = (yf+yi+1)/2;
	decomp(xi,yi,xm,ym,'1');
	decomp(xi,ym,xm,yf,'2');
	decomp(xm,yi,xf,ym,'3');
	decomp(xm,ym,xf,yf,'4');
}

int main(){FIN
	char P;
	string ns,ms;
	ll p;
	string aux;
	while(cin >> P && P!='#'){
		cin >> n >> m;
		ns = to_string(n);
		ms = to_string(m);
		bm.assign(n,vbool(m,0));
		if(P=='B'){
			s="";
			while(SZ(s)<(n*m)){
				cin >> aux;
				s+=aux;
			}
			cout << "D" << string(4-SZ(ns),' ') << n << string(4-SZ(ms),' ') << m << "\n";
			fore(i,0,n){
				fore(j,0,m){
					p = (i*m)+j;
					if(s[p]=='1')bm[i][j]=1;
				}
			}
			ans = "";
			comp(0,0,n,m);
			fore(i,0,SZ(ans)){
				if(i && i%50 == 0) cout << "\n";
				cout << ans[i];
			}
			cout << "\n";
		}
		else{
			aa=cin.get();
			cout << "B" << string(4-SZ(ns),' ') << n << string(4-SZ(ms),' ') << m << "\n";
			posD=-1;s="";
			decomp(0,0,n,m,'1');
			fore(i,0,n){
				fore(j,0,m){
					p = (i*m)+j;
					if(p && p%50==0) cout << "\n";
					cout << bm[i][j];
				}
			}
			cout << "\n";
		}
	}
	return 0;
}
