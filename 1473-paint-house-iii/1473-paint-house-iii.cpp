class Solution {
public:
    
    static const int INF = 1000001;
    int dp[100][100][21];
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        memset(dp, -1, sizeof(dp));
        
        int ans = dfs(houses, cost, m, n, target, 0, 0, 0);
        
        if(ans < INF)
            return ans;
        else
            return -1;
    }
    
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int i, int nbr, int left){
        
        // base cases      
        // all houses have been painted
        if(i == m){
            return nbr == target ? 0 : INF;
        }
        
        // nbr has exceeded req targets
        if(nbr > target){
            return INF;
        }
        
        // memoization
        if(dp[i][nbr][left] != -1)
            return dp[i][nbr][left];
        
        // not painted
        if(houses[i] == 0){            
            int minCost = INF;
            
            // minCost after trying all the colors
            for(int c=1; c<=n; c++){      
                int new_nbr = nbr;
                if(c != left ){
                    new_nbr = nbr + 1;
                }    
                minCost = min(minCost, cost[i][c-1] + dfs(houses, cost, m, n, target, i+1, new_nbr, c));   
            }
            return dp[i][nbr][left] = minCost;
        }
        
        // painted
        else{   
            int new_nbr = nbr;
            if(houses[i] != left){
                new_nbr = nbr + 1;
            }
            return dp[i][nbr][left] = dfs(houses, cost, m, n, target, i+1, new_nbr, houses[i]);
        }
    }
};