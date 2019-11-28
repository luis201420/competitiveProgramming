#include <bits/stdc++.h>

using namespace std;

int main(){
	string n,m;
	int c,ans,a,b,i;
	while(cin >> n >> m){
		if(n=="0" && m=="0")break;
		reverse(n.begin(),n.end());
		reverse(m.begin(),m.end());
		ans=c=0;
		
		for(i=0;i<min(m.size(),n.size());i++){
			a=n[i]-'0';
			b=m[i]-'0';
			if((a+b+c)>=10){
				c=1;
				ans++;
			}
			else{
				c=0;
			}
		}

		if(n.size()<m.size())swap(n,m);

		for(;i<n.size();i++){
			a=n[i]-'0';
			if(a+c>=10){
				c=1;
				ans++;
			}
			else{c=0;}
		}

		if(ans==0){
			cout << "No carry operation." << endl;
		}
		else{
			cout << ans << " carry operation";
			if(ans>1)cout << "s";
			cout <<"."<< endl;
		}
	}
	return 0;
}
