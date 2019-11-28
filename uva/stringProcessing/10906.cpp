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

int main(){FIN

	ll t,n;
	string line;
	string v1, v2, v3,acum,op;

	map<string, vector<string>> mp;
	cin >> t;
	
	fore(i,0,t){
		cout << "Expression #"<<i+1 << ": ";
		cin >> n;
		getline(cin,line);
		fore(j,0,n){
			getline(cin,line);
			acum=op="";
			fore(k,0,SZ(line)){
				if(line[k]==' ') continue;
				else if(line[k]=='='){v1 = acum;acum="";}
				else if(line[k]=='+' || line[k]=='*'){v2 = acum; op+=line[k]; acum="";}
				else acum += line[k];
			}
			v3 = acum;
			//DBG(v1); DBG(v2);DBG(v3);DBG(op);
			//cerr << SZ(mp[v2]) << " " << SZ(mp[v3]) << endl;
			if(SZ(mp[v2])>0){
				if(mp[v2][1]=="+" && op=="*") v2 = "("+mp[v2][0]+mp[v2][1]+mp[v2][2]+")";	
				else v2 = mp[v2][0]+mp[v2][1]+mp[v2][2];
			}
			if(SZ(mp[v3])>0){	
				if(mp[v3][1]==op || (mp[v3][1]=="+" && op=="*")) v3 = "("+mp[v3][0]+mp[v3][1]+mp[v3][2]+")";	
				else v3 = mp[v3][0]+mp[v3][1]+mp[v3][2];
			}
			mp[v1] = {v2,op,v3};
			if(j==(n-1)){
				cout << v2+op+v3 << "\n";
			}
		}
		mp.clear();
	}
	return 0;
}
