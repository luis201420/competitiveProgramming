#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n,m,v,cont,k,best,res;
	vector<long long> nums,sum;
	cont=1;

	while(cin >> n){
		if(n==0)break;
		while(n--){
			cin >> v;
			nums.push_back(v);
		}
		for(int i=0;i<nums.size();i++){
			for(int j=i+1;j<nums.size();j++){
				sum.push_back(nums[i]+nums[j]);
			}
		}

		cout << "Case "<< cont << ":" << endl;
		cin >> m;
		while(m--){
			
			cin >> v;

			best = 10000000000;
			k=0;
			while(k<sum.size()){
				if(abs(sum[k]-v)<best){
					res=sum[k];
					best=abs(sum[k]-v);
				}
				k++;
			}
			cout << "Closest sum to " << v << " is " << res << "." << endl;
		}
		cont++;
		sum.clear();
		nums.clear();
	}
	return 0;
}
