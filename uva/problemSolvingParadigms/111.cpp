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

ll n;

ll LIS(vll & a){
	
	ll lisV[n];
	lisV[0] = 1;

	ll ans = 1;
	
	fore(i,1,n){
		lisV[i]=1;
		fore(j,0,i){
			if(a[j] < a[i] && lisV[i] < lisV[j]+1)
				lisV[i] = lisV[j]+1;
		}
		ans = max(ans,lisV[i]);
	}
	return ans;
}

int main(){FIN
	ll cont;
	ll rank[21];
	string line,aux;
	vll ns;

	getline(cin,line);
	n = atoi(line.c_str());

	while(getline(cin,line)){	

		cont=0;
		fore(i,0,SZ(line)){
			if(line[i]!=' ')aux+=line[i];
			else{
				rank[cont++] = atoi(aux.c_str());
				aux="";
			}
		}

		rank[cont++] = atoi(aux.c_str());
		aux="";
		ns.resize(cont);

		while(getline(cin,line) && SZ(line) > 2){
			
			cont = 0;
			fore(i,0,SZ(line)){
				if(line[i] != ' ')aux+=line[i];
				else{
					ns[atoi(aux.c_str())-1] = rank[cont++];
					aux="";
				}
			}
			ns[atoi(aux.c_str())-1] = rank[cont++];
			aux="";
			
			cout << LIS(ns) << "\n";
		}
		n = atoi(line.c_str());
	}	
	return 0;
}
