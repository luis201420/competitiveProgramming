#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

#define MAX_FACT 20
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll fact;

void pre_fact( ){
	fact[0]=1;
	fore(i,1,MAX_FACT+1){
		fact[i] = i*fact[i-1];
	}
}

string NPermutarion(string &a, ll n){
	
	string ans="";
	vll cont(26,0);
	fore(i,0,SZ(a))cont[a[i]-'a']++;
	
	fact.resize(MAX_FACT);
	pre_fact();

	ll sum,xsum;
	sum = 0;

	//DBG(cont[0]);

	while(sum != n){
		sum = 0;
		fore(i,0,27){
			if(cont[i]==0)continue;

			cont[i]--;

			xsum = fact[SZ(a)-1-SZ(ans)];
			fore(j,0,26) xsum /= fact[cont[j]];
			sum += xsum;

			if(sum >= n){
				ans += 'a'+i;
				n -= (sum-xsum);
				break;
			}
			if(sum < n) cont[i]++;
		}
	}

	for(int i = 25; SZ(ans)<SZ(a) && i>=0;i--){
		if(cont[i]){
			ans+='a'+i;
			cont[i++]--;
		}
	}
	return ans;
}

int main(){FIN
	ll t,n;
	string s;
	cin >> t;
	while(t--){
		cin >> s >> n;
		cout << NPermutarion(s,n+1) << "\n";
	}
	return 0;
}
