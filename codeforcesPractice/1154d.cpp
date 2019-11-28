#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,b,a;
	cin >> n >> b >> a;
	vector<int> s(n);
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	int ans = 0;
	for(int i=0;i<n;i++,ans++){
		if(s[i]==1){
			if(a==0){
				b--;
				a++;
			}
			else a--;
		}
		else{
			if(a>0)a--;
			else if(b>0) b--;
			else break;
		}
	}
	cout << ans << endl;
	return 0;
}
