class Solution {
  public:
  
    // Time: O(n log n)  Space: O(maxDeadline)

    int findSlot(int x, vector<int> &par){
        if(par[x] == x) return x;
        return par[x] = findSlot(par[x], par);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        
        int n = deadline.size();
        vector<pair<int,int>> v;
        int mx = 0;

        for(int i=0;i<n;i++){
            v.push_back({profit[i], deadline[i]});
            mx = max(mx, deadline[i]);
        }

        sort(v.begin(), v.end(), greater<pair<int,int>>());

        vector<int> par(mx+1);
        for(int i=0;i<=mx;i++) par[i] = i;

        int cnt = 0;
        int sum = 0;

        for(auto &it : v){
            int p = it.first;
            int d = it.second;

            int pos = findSlot(d, par);

            if(pos > 0){
                cnt++;
                sum += p;
                par[pos] = findSlot(pos-1, par);
            }
        }

        return {cnt, sum};
    }
};