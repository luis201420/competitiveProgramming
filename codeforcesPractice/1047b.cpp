#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n,a,b;
    long long ans=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        ans=max(ans,a+b);
    }
    cout << ans << endl;
    return 0;
}
