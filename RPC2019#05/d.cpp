#include<bits/stdc++.h>

using namespace std;

vector<long long> tree,A;
int n,m;

void add(int k,long long x){
	while(k<=n){
		tree[k]+=x;
		k+=(k&-k);
	}
}

long long sum(int k){
	long long s=0;
	while(k>=1){
		s+=tree[k];
		k-=(k&-k);
	}
	return s;
}

long long verificate(int x){
	return abs((2*sum(x-1))+A[x-1]-sum(n))-(long long)(A[x-1]&1);
}

int binarySearch(long long v){
	int x=1, y=n, k;
		while(x<=y){
		k=(x+y)/2;
		if(sum(k)==v) break;
		if(sum(k)<v) x=k+1;
		else y=k-1;
	}
	return k;
}

int main(){
	
	cin >> n >> m;
	
	A.resize(n);
	tree.assign(n+1,0);
	
	for(int i=0;i<n;i++){
		cin >> A[i];
		add(i+1,A[i]);
	}
	
	long long pos,v,obj,ans;
	long long v1,v2,v3,v4,v5;

	while(m--){
		cin >> pos >> v;
		add(pos+1,v-A[pos]);
		A[pos]=v;
		obj=sum(n);
		obj/=2;
		ans = binarySearch(obj);
		//cerr <<ans<<" "<< sum(ans) << " " << sum(n) << endl;
		v1 = abs(verificate(ans));
		v2 = abs(verificate(ans-1));
		v3 = abs(verificate(ans+1));
		v4 = abs(verificate(ans+2));
		v5 = abs(verificate(ans-2));
		//cerr << v1 << " " << v2 << " " << v3 << endl;
		//cerr << sum(ans) << " " << sum(ans-1) << " " << sum(ans+1)<< endl;
		if(v5 <= v4 && v5 <= v3 && v5 <= v2 && v5 <= v1) cout << ans-3 << endl;
		else if(v2 <= v5 && v2 <= v4 && v2 <= v3 && v2 <= v1) cout << ans-2 << endl;
		else if(v1 <= v3 && v1 <= v2 && v1 <= v4 && v1 <= v5) cout << ans-1 << endl;
		else if(v3 <= v5 && v3 <= v4 && v3 <= v2 && v3 <= v1) cout << ans << endl;
		else cout << ans+1 << endl;
	}
	return 0;
}
