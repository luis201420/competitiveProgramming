#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

#define SQR(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 11

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<string> vstr;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<vbool> vvbool;

#define L(i) (i<<1)+1
#define R(i) (i+1)<<1

vector<bitset<26>> tree;
string A;

void create_tree(int i, int a, int b){
	if(a==b){
		tree[i].set(A[a]-'a');
		return;
	}
	int m = (a+b)/2;
	create_tree(L(i),a,m);
	create_tree(R(i),m+1,b);
	tree[i] = (tree[L(i)] | tree[R(i)]);
}

void update_tree(int i, int a, int b, int ua, int ub, int v){
	if(ub < a || b < ua) return;
	if(ua <= a && b <= ub){
		tree[i].reset();
		tree[i].set(v);
		return;
	}
	int m=(a+b)/2;
	update_tree(L(i),a,m,ua,ub,v);
	update_tree(R(i),m+1,b,ua,ub,v);
	tree[i] = (tree[L(i)] | tree[R(i)]);
}

bitset<26> rmq_tree(int i, int a, int b, int qa, int qb){
	if(qb < a || b < qa) return 0;
	if(qa <= a && b <= qb) return tree[i];
	int m = (a+b)/2;
	bitset<26> v1 = rmq_tree(L(i),a,m,qa,qb);
	bitset<26> v2 = rmq_tree(R(i),m+1,b,qa,qb);
	return (v1|v2);
}

int main(){FIN
	ll q;
	ll op,l,r,pp;
	char cc;
	bitset<26> ans;

	cin >> A;
	tree.assign(4*A.size(),bitset<26>());

	create_tree(0,0,A.size()-1);
	
	cin >> q;
	while(q--){
		cin >> op;
		if(op == 1){
			cin >> pp >> cc;
			update_tree(0,0,A.size()-1,pp-1,pp-1,(cc-'a'));
		}
		else{
			cin >> l >> r;
			ans = rmq_tree(0,0,A.size()-1,l-1,r-1);
			cout << ans.count() << "\n";
		}
	}
	return 0;
}
