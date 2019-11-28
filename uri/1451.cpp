#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string line,ans,aux;
	bool pos;
	while(cin >> line){
		ans="";
		for(int i=0;i<line.size();i++){
			if(line[i]=='['){
				aux="";
				i++;
				while(i<line.size() && line[i]!=']' && line[i]!='[')aux+=line[i++];
				i--;
				ans=aux+ans;
			}
			else if(line[i]!=']'){
				ans+=line[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
