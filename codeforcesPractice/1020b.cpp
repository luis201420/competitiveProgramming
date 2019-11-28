#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> ns(n);
	for(int i=0;i<n;i++){
		cin >> ns[i];
	}
	int p;
	vector<bool> visited;
	for(int i=0;i<n;i++){
		p=ns[i]-1;
		visited.assign(n,0);
		visited[i]=1;
		while(!visited[p]){
			visited[p]=1;
			p=ns[p]-1;
		}
		if(i!=0)cout << " ";
		cout << p+1;
	}
	cout << endl;
	return 0;
}
