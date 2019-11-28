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

	string line;
	ll i,f;
	bool ver,pasE,pasP;

	while(getline(cin,line)){
	
		i=0;
		while(i<SZ(line) && (line[i]==' '|| line[i]=='\t'))i++;
		
		f=SZ(line)-1;
		while(f>=0 && (line[f]==' ' || line[f]=='\t'))f--;

		if(i<=f && line.substr(i,f-i+1)=="*") break;

		ver=1;
		pasE=0;
		pasP=0;

		//DBG(line);	
		//DBG(i); DBG(f);

		fore(j,i,f+1){
			if(line[j]==' '){ver=0;break;}
			if(line[j]=='E' || line[j]=='e'){
				if(pasE){ver=0;break;}
				if(j == f || j==i) {ver=0;break;}
				pasE=1;
			}
			if(line[j]=='.'){
				if(pasE || pasP){ver=0;break;}
				if((j-1)<i || (j+1)>=(f+1) || 
						((j-1)>=i && !isdigit(line[j-1])) ||
				 		((j+1)<(f+1) && !isdigit(line[j+1])) ){
						ver = 0; break;
				}
				pasP=1;
			}
			if(line[j]=='+' || line[j]=='-'){
				if(j>i && line[j-1]!='E' && line[j-1]!='e' ){ver=0;break;}
				if(j==i && !isdigit(line[j+1])){ver=0;break;}
				if(j == f){ver=0;break;}
			}
			//DBG(j);
		}
		
		cout << line.substr(i,f-i+1);
		
		if(ver&&(pasP||pasE)) cout << " is legal.\n";
		else cout << " is illegal.\n";
	}

	return 0;
}
