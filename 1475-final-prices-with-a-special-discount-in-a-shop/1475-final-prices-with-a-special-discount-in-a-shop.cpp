class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
    
        int n = prices.size();
        vector<int> ans(n);
        stack<int> s;
        
        for(int i=n-1; i>=0; i--){
            
            // till you find find smallest or equal element, pop
            while(!s.empty() && s.top() > prices[i]){
                s.pop();
            }
            
            if(s.empty()){   // if empty, no discount
                ans[i] = prices[i];
                s.push(prices[i]);
            }
            else{    // discount equal to top value
                ans[i] = prices[i] - s.top();
                s.push(prices[i]);
            }
        }
        
        return ans;
    }
};