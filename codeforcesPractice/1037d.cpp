#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> v[200005];

bool find(int x, int y){
	ll mid,low=0,high=v[x].size()-1;
	while(low<=high){
		mid=(low+high)/2;
		if(v[x][mid]>y)
			high=mid-1;
		else if(v[x][mid]<y)
			low=mid+1;
		else
			return true;
	}
	return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    ll n,i,x,y;
    cin>>n;	
    ll a[n+1]={0};
    for(i=0;i<n-1;i++){
    	cin>>x>>y;
    	v[x].push_back(y);
    	v[y].push_back(x);
    	a[y]++;
    	a[x]++;
    }
    for(i=1;i<=n;i++)
    	sort(v[i].begin(),v[i].end());
    ll b[n];
    for(i=0;i<n;i++)
    	cin>>b[i];
    if(b[0]!=1){
    	cout<<"No"<<endl;
    	return 0;
    }
    ll j=1;
    i=0;
    ll falg=0;
    while(j<n){
    	if(a[b[i]]==0){
    		i++;
    		continue;
    	}
    	if(find(b[i],b[j])){
    		a[b[i]]--;
    		a[b[j]]--;
    		j++;
    	}else{
    		falg=1;
    		break;
    	}
    }
    cout<<(falg==0 ? "Yes" : "No")<<endl;
}
