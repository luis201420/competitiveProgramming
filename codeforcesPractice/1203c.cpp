#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) s.size()
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

#define L(i) (i<<1)+1
#define R(i) (i+1)<<1

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll tree,A;

ll gcd(ll a, ll b){
	while(b){
		a%=b;
		swap(a,b);
	}
	return a;
}

void create_tree(int i, int a, int b){
	if(a==b){
		tree[i]=A[a];
		return;
	}
	int m = (a+b)/2;
	create_tree(L(i),a,m);
	create_tree(R(i),m+1,b);
	tree[i]=gcd(tree[L(i)],tree[R(i)]);
}

ll fact(ll n){
	ll cont=0;
	for(ll d=1;d*d<=n;d++){
		if(n%d==0){
			cont++;
			if((n/d)!=d)cont++;
		}
	}
	return cont;
}

int main(){FIN

	ll n;
	
	cin >> n;	
	A.resize(n);
	
	for(int i=0;i<n;i++)cin >> A[i];

	tree.assign(4*n,0);
	create_tree(0,0,n-1);
	
	ll gcd = tree[0];

	cout << fact(gcd) << "\n";
	
	return 0;
}
