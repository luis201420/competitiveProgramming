#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<priority_queue<int>> t,bk;
	int n,m,a,b;
	cin >> n >> m;
	t.assign(n+1,priority_queue<int>());
	for(int i=0;i<m;i++){
		cin >> a >> b;
		t[a].push(b);
	}
	long long res,aux,cont;
	bool v = 0;
	priority_queue<int> q;
	for(int j=1;j<=n;j++){
		cont = 0;
		res = 0;
		bk=t;
		while(cont<m){
			cerr  << "cont "<< cont << endl;
			for(int i=j;i<(n+j);i++){
				int id = (i==5)?5 : i%n;
				if(!q.empty())cerr << "q" << q.top() << endl;
				//cerr << "i " << i <<" " <<  j<< endl;
				while(!q.empty() && (id)==-(q.top())){
					cont++;	
					q.pop();
					//cerr << "c" << endl;
				}
				if(!t[id].empty()){
					cerr << "i " << t[id].top()<<endl;
					aux=t[id].top();
					t[id].pop();
					q.push(-aux);
				}
			}
			if(cont<m)res+=n;
		}
		while(!q.empty()){
			//cerr << "d" << endl;
			aux=q.top();
			q.pop();
		}
		res+=aux;
		cerr << res << endl;
		t=bk;
	}
	return 0;
}
