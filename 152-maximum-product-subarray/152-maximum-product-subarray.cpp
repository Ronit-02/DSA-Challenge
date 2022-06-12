class Solution {
public:
    int maxProduct(vector<int>& arr) {
        
        int n = arr.size();
        
        int ma = arr[0];
        int mi = arr[0];
        int ans = arr[0];
        
        for(int i=1; i<n; i++){
            
            if(arr[i] < 0)
                swap(ma, mi);
            
            ma = max(arr[i], ma*arr[i]);
            mi = min(arr[i], mi*arr[i]);
            ans = max(ans, ma);
        }
        
        return ans;
    }
};