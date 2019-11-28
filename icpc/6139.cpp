#include <bits/stdc++.h>

#define L(i) (i<<1)+1
#define R(i) (i+1)<<1

using namespace std;

vector<int> A,st;

void create(int i,int a,int b){
	if(a==b){
		if(A[a]>0)st[i]=1;
		else if(A[a]<0)st[i]=-1;
		else st[i]=0;
		return;
	}
	int m = (a+b)/2;
	create(L(i),a,m);
	create(R(i),m+1,b);
	st[i]=st[L(i)]*st[R(i)];
}

void update(int i, int a, int b, int pos, int v){
	if(pos<a || b<pos) return;
	if(a==b && a==pos){
		if(v>0)st[i]=1;
		else if(v<0)st[i]=-1;
		else st[i]=0;
		return;
	}
	int m=(a+b)/2;
	update(L(i),a,m,pos,v);
	update(R(i),m+1,b,pos,v);
	st[i]=st[L(i)]*st[R(i)];
}

int mmq(int i, int a, int b, int qa, int qb){
	if(qb<a || b<qa)return 1;
	if(qa<=a && b<=qb){
		return st[i];
	}
	int m = (a+b)/2;
	int r1 = mmq(L(i),a,m,qa,qb);
	int r2 = mmq(R(i),m+1,b,qa,qb);
	return r1*r2;
}

int main(){
	int n,k;
	char op;
	int a,b,res;
	while(cin >> n >> k){
		A.resize(n);
		for(int i=0;i<n;i++)cin >> A[i];
		st.resize(4*n);
		create(0,0,n-1);
		for(int i=0;i<k;i++){
			cin >> op >> a >> b;
			if(op=='C'){
				update(0,0,n-1,a-1,b);
			}
			else{
				res=mmq(0,0,n-1,a-1,b-1);
				if(res==0)cout <<"0";
				else if(res>0)cout << "+";
				else cout << "-";
			}
		}
		cout << endl;
	}
	return 0;
}
