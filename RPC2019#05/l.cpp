#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,c;
	cin >> n >> c;
	vector<int> cs(c),ns(n,0);
	for(int i=0;i<c;i++){
		cin >> cs[i];
	}
	int minS;
	for(int i=0;i<c;i++){
		if(i!=0)cout << " ";
		minS=0;
		for(int j=1;j<n;j++){
			if(ns[minS]>ns[j]){
				minS=j;
			}
		}
		cout << minS+1;
		ns[minS]+=cs[i];
	}
	cout << endl;

	return 0;
}
