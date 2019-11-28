#include <bits/stdc++.h>

#define L(i) (i<<1)+1
#define R(i) (i+1)<<1
#define P(i) (i-1)>>1

using namespace std;

vector<int> lazy;            // flags of leaves
vector<pair<int,int>> tree;  // first->0 and second->1
string A;                    // array pirates

void create_tree(int i,int a,int b){
	if(a==b){
		if(A[a]=='1')tree[i].second++;
		else tree[i].first++;
		return;
	}
	int m = (a+b)/2;
	create_tree(L(i),a,m);
	create_tree(R(i),m+1,b);
	tree[i].first  = tree[L(i)].first  +  tree[R(i)].first;
	tree[i].second = tree[L(i)].second +  tree[R(i)].second;
}

inline void update_lazy_node(int i){
	if(lazy[i]==0){
		tree[i].first+=tree[i].second;
                tree[i].second=0;
	}
	if(lazy[i]==1){
		tree[i].second+=tree[i].first;
                tree[i].first=0;
	}
	if(lazy[i]==2){
		swap(tree[i].first,tree[i].second);
	}
}

inline void update_value_lazy(int i,int v){
	if(lazy[i]==0){
		if(v==0)lazy[i]=0;
		if(v==1)lazy[i]=1;
		if(v==2)lazy[i]=1;
	}
	if(lazy[i]==1){
		if(v==0)lazy[i]=0;
		if(v==1)lazy[i]=1;
		if(v==2)lazy[i]=0;
	}
	if(lazy[i]==2){
		if(v==0)lazy[i]=0;
		if(v==1)lazy[i]=1;
		if(v==2)lazy[i]=-1;
	}
}

int rmq(int i,int a,int b,int qa, int qb){
	if(qb<a || b<qa) return 0;          // special case	

	if(qa<=a && b <=qb){
		//cerr << "%" << i << "-> "<< tree[i].first<<","<<tree[i].second <<endl;
		return tree[i].second;
	}

	if(lazy[i]!=-1){
		//cerr << "+" << i << "." << lazy[i]<< endl;
                if(a!=b){  // propagetion to children
                        if(lazy[L(i)]!=-1)update_value_lazy(L(i),lazy[i]);
                        else lazy[L(i)]=lazy[i];

			update_lazy_node(L(i));

                        if(lazy[R(i)]!=-1)update_value_lazy(R(i),lazy[i]);
                        else lazy[R(i)]=lazy[i];

			update_lazy_node(R(i));
                }
                lazy[i]=-1; //lazy value reset
	}

	int m=(a+b)/2;
	int v1=rmq(L(i),a,m,qa,qb);
	int v2=rmq(R(i),m+1,b,qa,qb);
	return v1+v2;
}

void update_lazy(int i,int a,int b,int ua,int ub,int flag){  // flag = 0->E 1->F 2->I
	if(ub<a || b<ua) return;			

	if(ua<=a && b <=ub){
		//cerr << "*" << i << endl;
		if(lazy[i]!=-1){
			int aux = lazy[i];
			lazy[i]=flag;
			update_lazy_node(i);
			lazy[i]=aux;
			update_value_lazy(i,flag);
		}
		else{
			lazy[i]=flag;
			update_lazy_node(i);
		}
		return;
	}

	if(lazy[i]!=-1){
		
		if(a!=b){  // propagetion to children
			if(lazy[L(i)]!=-1)update_value_lazy(L(i),lazy[i]);
			else lazy[L(i)]=lazy[i];

			update_lazy_node(L(i));
			
			if(lazy[R(i)]!=-1)update_value_lazy(R(i),lazy[i]);
			else lazy[R(i)]=lazy[i];

			update_lazy_node(R(i));
		}
		lazy[i]=-1; //lazy value reset
        }

	int m=(a+b)/2;
	update_lazy(L(i),a,m,ua,ub,flag);
	update_lazy(R(i),m+1,b,ua,ub,flag);
	//cerr << "?" << i << endl;
	tree[i].first  = tree[L(i)].first  + tree[R(i)].first; // update nodes
	tree[i].second = tree[L(i)].second + tree[R(i)].second;
}

int main(){
	int t,m,n,q;  // t = no cases, q = no queries
	string s;
	int x,y,cont;
	char op;
	cin >> t;
	for(int i=1;i<=t;i++){
		cout << "Case " << i << ":"<<endl;
		cin >> m;
		A="";
		
		while(m--){
			cin >> n >> s;
			while(n--) A+=s;
		}

		tree.assign((4*A.size()),make_pair(0,0));
		lazy.assign(tree.size(),-1);

		create_tree(0,0,A.size()-1);
		
		cin >> q;
		cont = 1; 
		while(q--){
			cin >> op >> x >> y;
			if(op == 'F')update_lazy(0,0,A.size()-1,x,y,1);
			else if(op == 'E')update_lazy(0,0,A.size()-1,x,y,0);
			else if(op == 'I')update_lazy(0,0,A.size()-1,x,y,2);
			else cout << "Q"<<cont++ << ": " << rmq(0,0,A.size()-1,x,y) << endl;
		}
	}
	return 0;
}
