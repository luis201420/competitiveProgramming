#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	double d,c,m,t;
	long long td,tm,tc,tt;
	string s;
	while(cin >> s){
		d=c=m=1.0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='D')d+=(d/3.0);
			if(s[i]=='M')m+=(m/3.0);
			if(s[i]=='C')c+=(c/3.0);
		}
		t=d+c+m;
		td=floor(d);
		tm=floor(m);
		tc=floor(c);
		tt=floor(t);
		td = to_string(td).size();
		tm = to_string(tm).size();
		tc = to_string(tc).size();
		tt = to_string(tt).size();

		printf("%lld %lld %lld %lld\n",td,tm,tc,tt);
	}
	return 0;
}
