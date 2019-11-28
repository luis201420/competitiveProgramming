#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<vector<bool>> ver;
	float des[6]={1,0.5,0.25,0.25,0.25,0.25};
	vector<pair<long long,float>> trips;
	long long n,t;
	float c;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> t >> c;
		trips.push_back({t,c});
	}
	priority_queue<pair<float,vector<long long>>> pq;
	pq.push({-trips[0].second,{-trips[0].first,0,1}});
	long long curT,curI,curN;
	float curC;
	ver.assign(n,vector<bool>(6,0));
	while(!pq.empty()){
		curC = -(pq.top().first);
		curT = -(pq.top().second)[0];
		curI = (pq.top().second)[1];
		curN = (pq.top().second)[2];
		pq.pop();
		
		if(ver[curN-1][curI])continue;
		ver[curN-1][curI]=1;

		if(curN == n)break;
		
		if(curT < 120 && curI < 5){
			pq.push({-(curC+(des[int(curI+1)]*trips[curN].second)),{-(curT+trips[curN].first),curI+1,curN+1}});
		}
		pq.push({-(curC+(trips[curN].second)),{-(trips[curN].first),0,curN+1}});
	}
	cout << setprecision(2) << fixed;
	cout << curC << endl;
	return 0;
}
