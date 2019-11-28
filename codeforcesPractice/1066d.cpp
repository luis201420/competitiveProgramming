#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> obj(n);
	for(int i=0;i<n;i++){
		cin >> obj[i];
	}
	int box = 0;
	int sum = 0;
	for(int i=n-1;i>=0;i--){
		if(sum+obj[i] > k){
			box++;
			sum=0;
		}
		if(box == m || obj[i]>k){
			cout << n-(i+1) << endl;
			return 0;
		}
		sum+=obj[i];
	}
	cout << n << endl;
	return 0;
}
