#include <bits/stdc++.h>

using namespace std;

int main(){
	int v,s=0;
	priority_queue<int> q;
	for(int i=0;i<5;i++){
		cin >> v;
		s+=v;
		if(v%10!=0)q.push(10-(v%10));
	}
	if(!q.empty()) q.pop();
	
	while(!q.empty()){
		s+=q.top();
		q.pop();
	}
	
	cout << s << endl;
	return 0;
}
