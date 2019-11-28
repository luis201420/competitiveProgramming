#include <bits/stdc++.h>

using namespace std;

vector<vector<set<int>>> T;
vector<int> A;

void create(){
        for(int i=0;i<A.size();i++){
                T[0][i].insert(A[i]);
        }
        int s;
        for(int i=1;(1<<i)<=A.size();i++){
                s=1<<(i-1);
                for(int j=0;(j+(s<<1))<=A.size();j++){
			T[i][j].insert(T[i-1][j].begin(),T[i-1][j].end());
			T[i][j].insert(T[i-1][j+s].begin(),T[i-1][j+s].end());
                        /*if(A[T[i-1][j]]<A[T[i-1][j+s]])
                                T[i][j]=T[i-1][j];
                        else
                                T[i][j]=T[i-1][j+s];*/
                }
        }
}

int query(int a,int b){
        int s = (b-a)+1;
        int k = log2(s);
	set<int> res;
	res.insert(T[k][a].begin(),T[k][a].end());
	res.insert(T[k][(b-(1<<k))+1].begin(),T[k][(b-(1<<k))+1].end());
	return res.size();
        //return min(A[T[k][a]],A[T[k][(b-(1<<k))+1]]);
}

int main(){
	int n,v,q,x,y;
	cin >> n;
	while(n--){
		cin >> v;
		A.push_back(v);
	}

	T.assign(log2(A.size())+1,vector<set<int>>(A.size(),set<int>()));
	create();

	cin >> q;
	while(q--){
		cin >> x >> y;
		cout << query(x-1,y-1) << endl;
	}
	return 0;
}
