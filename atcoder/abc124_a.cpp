#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	int ans = max(a,b);
	if(ans == a){
		ans+=max(a-1,b);
	}
	else{
		ans+=max(a,b-1);
	}
	cout << ans << endl;
	return 0;
}
