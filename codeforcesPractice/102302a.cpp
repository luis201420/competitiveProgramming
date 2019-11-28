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
vll A;
vll tree;
ll n;

void create_tree(int i, int a, int b){
	if(a==b){
		tree[i]=n;
		return;
	}
	int m = (a+b)/2;
	create_tree(L(i),a,m);
	create_tree(R(i),m+1,b);
	tree[i] = min(tree[L(i)],tree[R(i)]);
}

void update_tree(int i, int a, int b, int ua, int ub, int val){
	if(ub < a || b < ua) return;
	if(ua <= a && b <= ub){
		tree[i]=val;
		return;
	}
	int m = (a+b)/2;
	update_tree(L(i),a,m,ua,ub,val);
	update_tree(R(i),m+1,b,ua,ub,val);
	tree[i] = min(tree[L(i)],tree[R(i)]);
}

int rmq(int i, int a, int b, int qa, int qb){
	if(qb < a || b < qa) return 1e9;
	if(qa <= a && b <= qb){
		return tree[i];
	}
	int m = (a+b)/2;
	int v1 = rmq(L(i),a,m,qa,qb);
	int v2 = rmq(R(i),m+1,b,qa,qb);
	return min(v1,v2);
}

bool myComp(const pll &p1, const pll &p2){
	if(p1.fst == p2.fst)
		return p1.snd < p2.snd;
	return p1.fst > p2.fst;
}

int main(){FIN
	
	ll v;
	vpll ord;
	vll ans;

	cin >> n;
	
	A.resize(n);
	ans.resize(n);

	fore(i,0,n){
		cin >> A[i];
		ord.pb({A[i],i});
	}
	
	sort(ALL(ord),myComp);
	
	tree.assign(4*n,1e9);
	create_tree(0,0,n-1);

	fore(i,0,n){
		v = rmq(0,0,n-1,ord[i].snd,n-1);
		//DBG(v);
		//DBG(ord[i].snd);
		ans[ord[i].snd] = min(v-ord[i].snd-1,ord[i].fst);
		update_tree(0,0,n-1,ord[i].snd,ord[i].snd,ord[i].snd);
	}

	fore(i,0,n){
		if(i) cout << " ";
		cout << ans[i];
	}
	cout << "\n";

	return 0;
}
