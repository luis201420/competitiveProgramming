#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string s;
	cin >> n;
	bool v;
	while(n--){
		cin >> s;
		sort(s.begin(),s.end());
		v=1;
		for(int i=0;i<s.size()-1;i++){
			if((s[i+1]-s[i])!=1){
				v=0;
				break;
			}
		}
		if(v) cout << "Yes" << endl;
		else cout << "No"  << endl;
	}
	return 0;
}
