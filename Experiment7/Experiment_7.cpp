class Solution 
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<long long> dist(n, 1e18);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) 
        {
            vector<long long> temp = dist;
            for (auto& f : flights) 
            {
                int u = f[0];
                int v = f[1];
                int price = f[2];

                if (dist[u] != 1e18) 
                {
                    temp[v] = min(temp[v], dist[u] + price);
                }
            }
            dist = temp;
        }

        return (dist[dst] == 1e18) ? -1 : (int)dist[dst];
    }
};