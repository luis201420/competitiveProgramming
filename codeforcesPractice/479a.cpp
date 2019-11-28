#include <bits/stdc++.h>

using namespace std;


int main(){
	int a,b,c;
	cin >> a >> b >> c;
	vector<int> ans;
	ans.push_back(a*b*c);
	ans.push_back(a+(b*c));
	ans.push_back((a*b)+c);
	ans.push_back(a+b+c);
	ans.push_back((a+b)*c);
	ans.push_back(a*(b+c));

	sort(ans.begin(),ans.end(),greater<int>());
	cout << ans[0] << endl;
	return 0;
}
