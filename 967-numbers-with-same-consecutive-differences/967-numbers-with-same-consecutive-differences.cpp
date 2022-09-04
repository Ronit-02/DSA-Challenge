class Solution {
private:
    void dfs(int n, int k, vector<int> &ans, int num){
        
        if(n == 0){
            ans.push_back(num);
            return;
        }
        
        for(int i=0; i<=9; i++){
            int ld = num % 10;
            
            if(abs(ld - i) == k)
                dfs(n-1, k, ans, num*10+i);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> ans;
        
        for(int i=1; i<=9; i++)
            dfs(n-1, k, ans, i);
        
        return ans;
    }
};