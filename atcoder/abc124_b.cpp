#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> m(n);
	int ans=0;
	bool v;
	for(int i=0;i<n;i++){
		cin >> m[i];
		int j=i-1;
		v=1;
		while(j>=0){
			if(m[j]>m[i]){
				v=0;
				break;
			}
			j--;
		}
		ans+=v;
	}
	cout << ans << endl;
	return 0;
}
