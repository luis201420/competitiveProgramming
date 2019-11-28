#include <bits/stdc++.h>

using namespace std;

int main(){
	
	vector<int> sticks;
	int n,value,sumT;
	cin >> n;
	
	for(int k=0;k<n;k++){
		cin >> value;
		sticks.push_back(value);
	}

	sort(sticks.begin(),sticks.end(),greater<int>());
	for(int i=0;i<n;i++){
		sumT=0;
		for(int j=i+1;j<n;j++){
			sumT+=sticks[j];
		}
		if(sticks[i]<sumT){
			cout << sticks.size()-i;
			break;
		}
	}
	if(sumT==0)cout << 0;
	return 0;
}
