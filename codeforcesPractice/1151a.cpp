#include <bits/stdc++.h>

using namespace std;

int dif(string a, string b){
	int r1,r2,ans=0;
	int ac,bc;
	for(int i=0;i<a.size();i++){
		ac=a[i]-'A';
		bc=b[i]-'A';
		r1=(max(ac,bc)-min(ac,bc));
		r2=(min(ac,bc)+26)-max(ac,bc);
		ans+=min(r1,r2);
	}
	return ans;
}

int main(){
	int n;
	string s,g="ACTG";
	cin >> n;
	cin >> s;
	int ans = 1e9;
	for(int i=0;i<n-3;i++){
		ans=min(ans,dif(s.substr(i,4),g));
	}
	cout << ans << endl;
	return 0;
}
