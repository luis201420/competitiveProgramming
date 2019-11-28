#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n,k,v,res,cont;
	string s;
	vector<long long> d;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> v;
		d.push_back(v);
	}
	cin >> s;
	res=0;
	//priority_queue<long long> q;
	for(int i=0;i<s.size();i++){
		priority_queue<long long> q;
		while((i+1)<s.size() && s[i]==s[i+1]){
			q.push(d[i]);
			i++;
		}
		q.push(d[i]);
		cont=1;
		while(/*!q.empty()*/ cont<=k && !q.empty()){
			//if(cont<=k){
				//cerr << q.top()<<endl;
				res+=q.top();
			//}
			q.pop();
			cont++;
		}
		//cerr << "----" << endl;
	}
	cout << res << endl;
	return 0;
}
