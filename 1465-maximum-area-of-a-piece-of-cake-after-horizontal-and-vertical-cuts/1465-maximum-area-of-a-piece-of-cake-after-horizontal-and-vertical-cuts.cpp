class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        
        hC.push_back(h);                 // including boundary value
        sort(hC.begin(), hC.end());      // sorting
        
        int x = hC[0];                    
        for(int i = 1; i < hC.size(); i++){  
            x = max(x, hC[i] - hC[i-1]);
        }
    
        vC.push_back(w);              
        sort(vC.begin(), vC.end());
        
        int y = vC[0];
        for(int i = 1; i < vC.size(); i++){
            y = max(y, vC[i] - vC[i-1]);
        }
        
        return (1LL * x * y) % 1000000007;
    }
};