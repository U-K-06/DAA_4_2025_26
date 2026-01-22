class Solution {
  public:
    bool solve(vector<int>& arr,int i,int sum,int curr)
    {
       if(sum == curr)
        {
            return true;
        }
        if(i >= arr.size() || curr > sum)
        {
            return false;
        }
        if(solve(arr,i+1,sum,curr+arr[i])) return true;
        return solve(arr,i+1,sum,curr);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        return solve(arr,0,sum,0);
        
    }
};