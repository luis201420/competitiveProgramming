#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,nc,aux;
	string s,r,c;
	cin >> n;
	while(n--){
		cin >> s;
	       	r=c="";	
		if(s[0]=='R'&& isdigit(s[1])){
			int i=1;
			while(i<s.size() && isdigit(s[i])){
				r+=s[i];
				i++;
			}
			i++;
			while(i<s.size() && isdigit(s[i])){
				c+=s[i];
				i++;
			}
			nc = atoi(c.c_str());
			c = "";
			
			while(nc>0){
				aux=(nc%26);
				if(aux>0){
					aux--;
					c+=('A'+aux);
				}
				else{
					c+='Z';
				}
				nc/=26;
			}
			reverse(c.begin(),c.end());
			cout << c+r << endl;
		}
		else{
			int i=0;
			while(i<s.size() && isalpha(s[i])){
				c+=s[i];
				i++;
			}
			while(i<s.size()){
				r+=s[i];
				i++;
			}
			reverse(c.begin(),c.end());
			nc=0;
			for(i=0;i<c.size();i++){
				nc+=(pow(26,i)*((c[i]-'A')+1));
			}
			cout << "R" << r << "C" << nc << endl;
		}
	}
	return 0;
}
