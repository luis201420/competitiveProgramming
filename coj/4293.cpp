#include<bits/stdc++.h> 

using namespace std;

typedef vector<int> vi;

long long it;

void merge(vi &arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    /*for(k=l;k<r;k++){
    	if(L[i]<=R[j]){
		arr[k]=L[i];
		i++;
	}
	else{
		arr[k]=R[j];
		j++;
		it=it+n1-i+1;
	}
    }*/
    
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
	    it=it+n1-i;
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++;
        it=it+n1-i;	
    } 
} 
  
void mergeSort(vi &arr, int l, int r) 
{ 
    if (l < r) 
    { 
        int m = (l+r)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
  
int main() 
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vi arr;
  	int n;
	while(cin >> n){ 
		if(n==0)break;
		it=0;
		arr.resize(n);
		for(int i=0;i<n;i++)cin >> arr[i];
		mergeSort(arr, 0, arr.size()-1); 
    		printf("%lld\n",it);
    	}
	return 0; 
} 
