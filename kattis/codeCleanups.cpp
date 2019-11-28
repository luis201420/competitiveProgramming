#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,v;
	cin >> n;
	vector<bool> bad_days(367,0);
	for(int i=0;i<n;i++){
		cin >> v;
		bad_days[v]=1;
	}
	int acum=0;
	int ans=0;
	int bad_count=0;

	for(int i=1;i<=366;){
		if(acum>=20){
			acum=0;
			bad_count=0;
			ans+=1;
			i--;
			continue;
		}
		acum+=bad_count;
		if(bad_days[i]) bad_count++;
		i++;
	}
	if(acum>0) ans++;
	cout << ans << endl;
	return 0;
}
