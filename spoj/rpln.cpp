#include <bits/stdc++.h>

#define L(i) (i<<1)+1
#define R(i) (i+1)<<1
#define INF 1e9

using namespace std;

vector<vector<int>> T;
vector<int> A;

void create(){
	for(int i=0;i<A.size();i++){
		T[0][i]=i;
	}
	int s;
	for(int i=1;(1<<i)<=A.size();i++){
		s=1<<(i-1);
		for(int j=0;(j+(s<<1))<=A.size();j++){
			if(A[T[i-1][j]]<A[T[i-1][j+s]])
				T[i][j]=T[i-1][j];
			else
				T[i][j]=T[i-1][j+s];
		}
	}
}

int rmq(int a,int b){
	int s = (b-a)+1;
	int k = log2(s);
	return min(A[T[k][a]],A[T[k][(b-(1<<k))+1]]);
}

int main(){
	int t,n,q,v,x,y;

	cin >> t;
	for(int i=1;i<=t;i++){

		cin >> n >> q;
		
		while(n--){
			cin >> v;
			A.push_back(v);
		}
		
		T.assign(log2(A.size())+1,vector<int>(A.size(),-1));

		create();
	
		cout << "Scenario #"<<i<<":"<<endl;
		
		while(q--){
			cin >> x >> y;
			cout << rmq(x-1,y-1)<<endl;
		}
		A.clear();
	}
	return 0;
}
