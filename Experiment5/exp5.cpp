#include <bits/stdc++.h>
using namespace std;



int subset(vector<int>&arr,int s,int n){
	
	if(s==0){
		return 1;
	}
	if(n==0 || s<0){
		return 0;
	}
	
	
	int include = subset(arr, s - arr[n - 1], n - 1);
	int exclude = subset(arr,s,n-1);
	
	return include + exclude;
	
	
}

int subset2(vector<int>&arr,int s,int n,vector<vector<int>> dp){
	if(s==0){return 1;}
	if(n==0 || s<0){return 0;};
	if (dp[n][s] != -1) {
        return dp[n][s];
     }
	

    int include = subset2(arr, s - arr[n - 1], n - 1, dp);
    
    int exclude = subset2(arr, s, n - 1, dp);

    return dp[n][s] = include + exclude;
}



int subset3(vector<int>&arr,int s){
	int n = arr.size();
	
	vector<vector<int>> dp(n + 1, vector<int>(s + 1));
		for (int i = 0; i <= n; ++i) {
        	dp[i][0] = 1;
    	}
        for (int i = 1; i <= n; ++i) {
        int curr = arr[i - 1];
        
        for (int j = 1; j <= s; ++j) {
            
            int exclude = dp[i - 1][j];

            int include = 0;
            if (curr <= j) {
 
                include = dp[i - 1][j - curr];
            }
            
            dp[i][j] = exclude + include;
        }
        
        
    } 
    return dp[n][s];
}


int main(){
	
		
		vector<int> arr = {1,2,3,4,5};
		int sum = 5 ;
		int n = arr.size();
		vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
		
		
		cout<< subset(arr,sum,n)<<endl;
		cout<< subset2(arr,sum,n,dp)<<endl;
		cout<<subset3(arr,sum);
		return 0;
		
	
	
}



// time complexity -- > brute force -- o(2^n) ---> using dp o(n*sum) 